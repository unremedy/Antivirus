#!/bin/bash
python3 -m pip install requests
python3 -m pip install tqdm
python3 -m pip install pathlib
echo "Downloading data base"
python3 install/main.py
echo "Compiling project"
cmake -H. -B_build
cmake --build _build
