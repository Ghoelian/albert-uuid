#include "albert/albert.h"
#include "albert/extension/queryhandler/standarditem.h"
#include "plugin.h"
#include <QLocale>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

using namespace albert;
using namespace std;

static shared_ptr<Item> buildItem() {
    boost::uuids::uuid uuid = boost::uuids::random_generator()();
    QString text = QString::fromStdString(boost::uuids::to_string(uuid));

    return StandardItem::make(
            "uuid",
            text,
            "Random UUID",
            QStringList({":uuid"}),
            {
                    {"copy", "Copy", [text]() { albert::setClipboardText(text); }}
            }
    );
}

vector<RankItem> Plugin::handleGlobalQuery(const GlobalQuery *query) const {
    vector<RankItem> r;
    const auto &s = query->string();

    if (QString t("uuid"); t.startsWith(query->string())) {
        r.emplace_back(buildItem(), (float) s.size() / t.size());
    }

    return r;
}
