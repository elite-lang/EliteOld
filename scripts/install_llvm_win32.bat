git clone --depth=1 -b release_36 https://github.com/llvm-mirror/llvm.git 
cd llvm
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX="C:/projects/elite/LLVM_SDK" ..
call "%VS140COMNTOOLS%vsvars32.bat" x86
devenv.exe "llvm.sln" /build release /project "install.vcxproj"
cd ../..
