CONFIG -= qt

TEMPLATE = lib
DEFINES += ALGOR_LIBRARY

VERSION = 1.0.0.0

CONFIG += c++20
CONFIG += build_all

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    src/ALGOR.hpp

SOURCES += \
    src/ALGOR.cpp

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
