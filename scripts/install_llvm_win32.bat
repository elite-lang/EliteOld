git clone --depth=1 -b release_36 https://github.com/llvm-mirror/llvm.git 
cd C:/projects/elite/llvm/build
cmake -DCMAKE_INSTALL_PREFIX="C:/projects/elite/LLVM_SDK" ..
"C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\Tools\vsvars32.bat"
devenv.exe "llvm.sln" /build release /project "install.vcxproj"
cd ../..

