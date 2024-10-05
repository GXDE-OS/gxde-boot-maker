TEMPLATE  = subdirs
CONFIG   += ordered

TRANSLATIONS_NAME = gxde-boot-maker
TRANSLATIONS += $$PWD/translations/$${TRANSLATIONS_NAME}.ts \
                $$PWD/translations/$${TRANSLATIONS_NAME}_zh_CN.ts

system(python3 $$PWD/tools/translate_generation.py $$PWD)

SUBDIRS += vendor/src/libxsys \
    libdbm

linux {
    SUBDIRS += service
}

SUBDIRS += app
