#!/bin/bash

# Compile/install libraries if required
if [ "$1" != "no-libs" ]; then
    # libmicrohttpd
    pushd ./libs/libhttpserver > /dev/null
    ./bootstrap
    mkdir build
    cd build
    ../configure
    make -j$(nproc)
    popd > /dev/null
fi

# Build module
mkdir -p build
cd build
cmake ..
make -j$(nproc)