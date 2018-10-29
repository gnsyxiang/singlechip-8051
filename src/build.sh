#!/bin/sh

ROOT=$(cd `dirname $0`; pwd)
INSTALL=$ROOT/install
SDCC=$ROOT/sdcc

if [ ! -d $INSTALL ];then
    mkdir -p $INSTALL
fi

if [ ! -d $SDCC ];then
    tar xjvf sdcc-src-20181029-10635.tar.bz2
fi

cd $SDCC
./configure --prefix=$ROOT/install
make -j5
make install
