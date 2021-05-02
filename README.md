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



