# Build module
mkdir -p build
cd build
cmake ..
make -j$(nproc)