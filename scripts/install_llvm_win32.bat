git clone --depth=1 -b release_36 https://github.com/llvm-mirror/llvm.git llvm
cd llvm
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX="C:/projects/elite/LLVM_SDK" ..
cd ../..

