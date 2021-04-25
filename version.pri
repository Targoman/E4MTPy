################################################################################
#   QBuildSystem
#
#   Copyright(c) 2021 by Targoman Intelligent Processing <http://tip.co.ir>
#
#   Redistribution and use in source and binary forms are allowed under the
#   terms of BSD License 2.0.
################################################################################
ProjectName="E4MTPy"
VERSION=0.1.0

#+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-
BOOST_PYTHON = $$system(ldconfig -p | grep boost_python3 | head -n 1 | sed s/.*lib// | sed s/.so.*//)
isEmpty(BOOST_PYTHON){
BOOST_PYTHON = $$system(ldconfig -p | grep boost_python-py3 | head -n 1 | sed s/.*lib// | sed s/.so.*//)
}
LIBS += -l$${BOOST_PYTHON}

#+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-
QT+= core network
QT -= gui
QMAKE_CXXFLAGS += -Wno-unknown-pragmas

#+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-
# Qt5.5.1 on OSX needs both c++11 and c++14!! the c++14 is not enough
QMAKE_CXXFLAGS += -std=c++11 -std=c++14
CONFIGS += c++11 c++14

#+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-
#following definitions are used on all Targoman projects
DEFINES += TARGOMAN_DEBUG_PROCESS_LINE=1
DEFINES += TARGOMAN_SHOW_WARNING=1
DEFINES += TARGOMAN_SHOW_INFO=1
DEFINES += TARGOMAN_SHOW_HAPPY=1
DEFINES += TARGOMAN_SHOW_NORMAL=1
