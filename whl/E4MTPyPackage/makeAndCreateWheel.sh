#! /bin/bash -v

ScriptDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

if [ ! -e "usr/bin/qmake" ]
then
   cd $ScriptDIR/../../ && qmake-qt5 && make  
else
   cd $ScriptDIR/../../ && qmake && make
fi
## /e4mt/wrapper/wheel/setup.py  should be prepared on github

E4MTPY=$ScriptDIR/src/E4MTPY
mkdir -p $E4MTPY
cd $E4MTPY
if [ ! -e ./libe4mtpy.so ]
then
    rm *
    echo "copying libraries"   
    cp $ScriptDIR/../out/lib64/lib*.so.*.1.* ./
    mv libE4MTPy.so.0.1.0 libe4mtpy.so
    mv libQJsonRPC.so.1.1.1 libQJsonRPC.so.1
    mv libTargomanCommon.so.1.1.1 libTargomanCommon.so.1
    mv libTargomanTextProcessor.so.1.1.1 libTargomanTextProcessor.so.1
    for L in ./lib*.so*; do
        patchelf --set-rpath '$ORIGIN' $L
    done
    echo 'from .libe4mtpy import *'>>./__init__.py
fi

python_lib=$(ldconfig -p | grep "libpython3." | head -n 1 | perl -pe 's%(.*)[=> ](.*)%\2%g')
boost_python_lib=$(ldconfig -p | grep "libboost_python3" | head -n 1 | perl -pe 's%(.*)[=> ](.*)%\2%g')
if [ -z "$boost_python_lib" ]
then
   boost_python_lib=$(ldconfig -p | grep "libboost_python-py3" | head -n 1 | perl -pe 's%(.*)[=> ](.*)%\2%g')
fi

cp $python_lib ./
cp $boost_python_lib ./

echo "building wheel ..."

cd ../../
python3 $ScriptDIR/setup.py bdist_wheel


