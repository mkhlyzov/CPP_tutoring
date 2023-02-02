#!/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

[ ! -d $SCRIPT_DIR/build ] && mkdir $SCRIPT_DIR/build

g++ $SCRIPT_DIR/main.cpp $SCRIPT_DIR/room.cpp $SCRIPT_DIR/property.cpp -o $SCRIPT_DIR/build/main.out -std=c++17
$SCRIPT_DIR/build/main.out