#! /bin/bash -v

scriptDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"  
E4MTPy=$scriptDIR/../../
dockers=('ubuntu20.04' 'ubuntu18.04' 'opensuse15.3' 'opensuse15.2')
for item in "${dockers[@]}"; do
	docker build -t make-whl:$item $scriptDIR/$item/
	docker run -it --rm -v $E4MTPy:/E4MTPy -v $scriptDIR/$item:/Wheels  make-whl:$item
done


