#pragma once

#include "albert/extension/queryhandler/globalqueryhandler.h"
#include "albert/plugin.h"
#include <boost/uuid/uuid_generators.hpp>

class Plugin : public albert::plugin::ExtensionPlugin<albert::GlobalQueryHandler> {
    Q_OBJECT ALBERT_PLUGIN

public:
    std::vector<albert::RankItem> handleGlobalQuery(const GlobalQuery*) const override;
};