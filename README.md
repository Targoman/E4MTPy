# E4MTPy
Python wrapper for [E4MT](https://github.com/Targoman/E4MT)

## Requirements
E4MTPy needs Python >= 3, Python3-pip, Qt5, libxml and libz.
## Installation
#### Using prepared wheels
1. Install Qt5, libxml and libz. 
    Assuming a fresh Ubuntu:20.04 installation, following command does the job:
    ```bash
    apt update && apt install -y libqt5core5a libqt5network5 libxml2-dev zlib1g-dev python3-pip
    ```
    or if you've installed Opensuse/leap:15, following command can be used:
    ```bash
    zypper install -y libxml2-devel zlib-devel libQt5Core-devel libQt5Network-devel python3-pip
    ```
2. We provided pip wheels for different versions of two linux distros ([Ubuntu20.04](https://github.com/Targoman/E4MTPy/releases/download/v0.1.0/Ubuntu20.04-E4MTPy-0.1.0-cp38-cp38-linux_x86_64.whl), [Ubuntu18.04](https://github.com/Targoman/E4MTPy/releases/download/v0.1.0/Ubuntu18.4-E4MTPy-0.1.0-cp36-cp36m-linux_x86_64.whl), [Opensuse/leap15.3](https://github.com/Targoman/E4MTPy/releases/download/v0.1.0/Opensuse15.3-E4MTPy-0.1.0-cp36-cp36m-linux_x86_64.whl), and [Opensuse/leap15.2](https://github.com/Targoman/E4MTPy/releases/download/v0.1.0/Opensuse15.2-E4MTPy-0.1.0-cp36-cp36m-linux_x86_64.whl)).
   After downloading, simply install it via pip like below:
   ```bash
   pip3 install Opensuse15.2-E4MTPy-0.1.0-cp36-cp36m-linux_x86_64.whl
   ```
#### Making your own wheel

1. Clone a fresh copy from github:
  ```bash
  git clone --recursive https://github.com/Targoman/E4MTPy.git
  ```
2. Based on your desired OS, update the provided Dockerfile in `whl/docker/` folder. Make sure you have the `docker` installed.
3. Run following commands:
  ```bash
  cd whl/ && bash makeWheel.sh
  ```
## Usage
Download `conf/` folder from root directory of this repo. It contains config files required for initializing E4MTPy.
```python
>>> import E4MTPy
>>> E4MTPy.init("conf/Normalization.conf", "conf/Abbreviations.tbl", "conf/SpellCorrectors", ["en", "fa"])                               
True

>>> E4MTPy.normalize("نتیجه ای که از این آزمایشها گرفته می شود، بسیار ارزشمند است.")
'نتیجه ای که از این آزمایشها گرفته می شود, بسیار ارزشمند است.'

>>> E4MTPy.tokenize("نتیجه ای که از این آزمایشها گرفته می شود، بسیار ارزشمند است.", "fa", _useSpellCorrector=True, _hinidiDigits=True, _arabicPunctuations=True, _breakSentences=False)
'نتیجه\u200cای که از این آزمایش\u200cها گرفته می\u200cشود ، بسیار ارزشمند است .'

>>> E4MTPy.text2IXML("این همایشها در تاریخ ۲۵ خرداد ماه برگزار میشوند.", "fa", _useSpellCorrector=True)
'این همایش\u200cها در تاریخ <Number>25</Number> خرداد ماه برگزار می\u200cشوند .'

>>> E4MTPy.ixml2Text("این همایش\u200cها در تاریخ <Number>25</Number> خرداد ماه برگزار می\u200cشوند .", _detokenize=True, _hinidiDigits=True, _arabicPunctuations=True, _breakSentences=False)
'این همایش\u200cها در تاریخ ۲۵ خرداد ماه برگزار می\u200cشوند.'

```
# License
E4MT is published under the terms of [LGPLv3 License](./LICENSE)



