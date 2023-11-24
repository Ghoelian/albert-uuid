project(uuid VERSION 1.0)

albert_plugin(
        NAME "UUID"
        DESCRIPTION "Generate UUIDs"
        LONG_DESCRIPTION "${CMAKE_CURRENT_SOURCE_DIR}/README.md"
        LICENSE BSD-2
        URL https://github.com/Ghoelian/albert-uuid
        MAINTAINERS @Ghoelian
        QT_DEPENDENCIES Widgets
        LIB_DEPENDENCIES boost
)
