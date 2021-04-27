# E4MTPy
Python wrapper for [E4MT](https://github.com/Targoman/E4MT)

## Requirements
E4MTPy needs Python >= 3, and Python3-pip.
## Installation
#### Using prepared wheels
We provided pip wheels for different versions of two linux distros (Ubuntu20.04, Ubuntu18.04, Opensuse/leap15.3, Opensuse/leap15.2 and Opensuse/leap15.1). They can be downloaded from [here]().
After downloading, simply install it via pip like below:
```bash
pip3 install E4MTPy-0.1.0-cp38-cp38-linux_x86_64.whl
```
#### Making your own wheel

1. Clone a fresh copy from github:
  ```bash
  git clone --recursive git@github.com:Targoman/E4MTPy.git
  ```
2. Based on your desired OS, update the provided Dockerfile in `whl/docker/` folder. Make sure you have the `docker` installed.
3. Run following commands:
  ```bash
  cd whl/ && bash makeWheel.sh
  ```
## Usage
Download `conf/` folder from root directory of this repo. It contains config files required for initializing E4MTPy.
```bash
>>> import E4MTPY
>>> E4MTPY.init("path/to/conf/Normalization.conf", "path/to/conf/Abbreviations.tbl", "path/to/conf/SpellCorrectors/", ["en", "fa"])
True
>>> E4MTPY.tokenize("ابزاری قدرتمند، برای فارسی زبانان!", "fa")                                                                                                   'ابزاری قدرتمند ، برای فارسی زبانان !' 
```
# License
E4MT is published under the terms of [LGPLv3 License](./LICENSE)



