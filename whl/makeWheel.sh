#! /bin/bash -v

scriptDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"  
E4MTPy=$scriptDIR/../
docker build -t make-wheel-ubuntu:20.04 docker/
docker run -it --rm -v $E4MTPy:/E4MTPy -v $scriptDIR:/Wheels  make-wheel-ubuntu:20.04

