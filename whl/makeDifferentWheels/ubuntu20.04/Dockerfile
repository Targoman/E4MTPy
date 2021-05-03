FROM ubuntu:20.04
LABEL Description="Creating wheel for e4mt on ubuntu 20.04 "

VOLUME ["/E4MTPy"]
VOLUME ["/Wheels"]
RUN apt update && DEBIAN_FRONTEND=noninteractive apt install -y --no-install-recommends build-essential git libqt5core5a libqt5network5 cmake qt5-qmake qtbase5-dev qt5-default libxml2-dev zlib1g-dev patchelf python3-dev libboost-python1.71.0 libboost-python1.71-dev python3-pip && pip3 install wheel && pip3 install setuptools
COPY ./runCreateWheelScript.sh /
ENTRYPOINT ["/bin/bash", "/runCreateWheelScript.sh"]



