git clone --depth=1 -b release_36 https://github.com/llvm-mirror/llvm.git 
cd llvm
mkdir build
cd build
call "%VS130COMNTOOLS%vsvars32.bat" x86
cmake -DCMAKE_INSTALL_PREFIX="C:/projects/elite/LLVM_SDK" ..
devenv "llvm.sln" /build release /project "install.vcxproj"
cd ../..
