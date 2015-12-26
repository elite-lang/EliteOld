git clone --depth=1 -b release_36 https://github.com/llvm-mirror/llvm.git 
cd llvm
mkdir build
cd build
cmake -Dcmake_install_prefix=../../LLVM_INSTALL ..
devenv "llvm.sln" /build release /project "install.vcxproj"
cd ../..
