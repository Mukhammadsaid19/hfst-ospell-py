#!/bin/bash
cmake ..
make -j4
# Note that this currently installs in /usr/lib, which isn't ideal
sudo make install
sudo make install-python