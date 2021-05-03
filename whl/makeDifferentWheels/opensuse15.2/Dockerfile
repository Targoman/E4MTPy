FROM opensuse/leap:15.2
LABEL Description="Creating wheel for e4mt on opensuse leap 15.2 "

VOLUME ["/E4MTPy"]
VOLUME ["/Wheels"]
RUN zypper install -y which git patchelf python3-devel python3-pip libxml2-devel zlib-devel libQt5Core-devel libQt5Network-devel libboost_python-py3-1_66_0 libboost_python-py3-1_66_0-devel && pip3 install wheel
COPY ./runCreateWheelScript.sh /
ENTRYPOINT ["/bin/bash", "/runCreateWheelScript.sh"]

