git clone --depth=1 -b release_36 https://github.com/llvm-mirror/llvm.git llvm
cd llvm
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX="C:/projects/elite/LLVM_SDK" ..
"C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\Tools\vsvars32.bat"
msbuild  /p:Configuration=Release "install.vcxproj"
cd ../..

