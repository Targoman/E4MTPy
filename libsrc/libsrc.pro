################################################################################
#   QBuildSystem
#
#   Copyright(c) 2021 by Targoman Intelligent Processing <http://tip.co.ir>
#
#   Redistribution and use in source and binary forms are allowed under the
#   terms of BSD License 2.0.
################################################################################
PYTHON_INCLUDE = $$system(ls -1d /usr/include/python3*)
message($${PYTHON_INCLUDE})
SOURCES += ./TextProcessor_boost_python.cpp
INCLUDEPATH += $${PYTHON_INCLUDE}
###############################################################################

include($$QBUILD_PATH/templates/libConfigs.pri)
