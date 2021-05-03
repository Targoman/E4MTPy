#! /bin/bash -v

cp -r /E4MTPy /tmp
bash /tmp/E4MTPy/whl/E4MTPyPackage/makeAndCreateWheel.sh
cp /tmp/E4MTPy/whl/E4MTPyPackage/dist/* /Wheels
