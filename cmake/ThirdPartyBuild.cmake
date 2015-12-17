include(cmake/ExternalProject.cmake)

set (third_party_install_path ${CMAKE_CURRENT_SOURCE_DIR}/extlib)

ExternalProject_Add(libiconv
	DOWNLOAD_DIR third_party/
	GIT_REPOSITORY https://github.com/elite-lang/libiconv
	SOURCE_DIR third_party/libiconv/
	CMAKE_COMMAND cmake
	CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${third_party_install_path}"
	# INSTALL_COMMAND ""
	BUILD_IN_SOURCE 0
	BUILD_ALWAYS 0
	)

ExternalProject_Add(libcharsetdetect
	DOWNLOAD_DIR third_party/
	GIT_REPOSITORY https://github.com/elite-lang/libcharsetdetect
	SOURCE_DIR third_party/libcharsetdetect/
	CMAKE_COMMAND cmake
	CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${third_party_install_path}"
	# INSTALL_COMMAND ""
	BUILD_IN_SOURCE 0
	BUILD_ALWAYS 0
	)

ExternalProject_Add(liblua
	DOWNLOAD_DIR third_party/
	GIT_REPOSITORY https://github.com/elite-lang/lua
	SOURCE_DIR third_party/lua/
	CMAKE_COMMAND cmake
	CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${third_party_install_path}"
	# INSTALL_COMMAND ""
	BUILD_IN_SOURCE 0
	BUILD_ALWAYS 0
	)






## oolua的构建
if (APPLE)
	set(OOLUA_BUILD_COMMAND "mac")
elseif (UNIX)
	set(OOLUA_BUILD_COMMAND "linux")
elseif (WIN32)
	set(OOLUA_BUILD_COMMAND "win32")
endif()

ExternalProject_Add(liboolua
	DEPENDS liblua
	DOWNLOAD_DIR third_party/
	GIT_REPOSITORY https://github.com/elite-lang/oolua
	SOURCE_DIR third_party/oolua/
	CONFIGURE_COMMAND ""
	BUILD_COMMAND make ${OOLUA_BUILD_COMMAND}
	BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/third_party/oolua/build_scripts/"
	INSTALL_COMMAND ""
	INSTALL_DIR ${third_party_install_path}
	)

if (UNIX)
	set(COPY_OOLUA_LIB_COMMAND "cp-unix")
elseif(WIN32)
	set(COPY_OOLUA_LIB_COMMAND "cp-win32")
endif()

## 在完成编译后，复制库
add_custom_command(OUTPUT copy-liboolua
  DEPENDS liboolua
  COMMAND make ${COPY_OOLUA_LIB_COMMAND}
  WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/third_party/oolua/build_scripts/"
  COMMENT "comment"
  ) 





ExternalProject_Add(libdyncall
	DOWNLOAD_DIR third_party/
	GIT_REPOSITORY https://github.com/elite-lang/dyncall
	SOURCE_DIR third_party/dyncall/
	CMAKE_COMMAND cmake
	CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${third_party_install_path}"
	# INSTALL_COMMAND ""
	BUILD_IN_SOURCE 0
	BUILD_ALWAYS 0
	)



ADD_CUSTOM_TARGET(deps
	DEPENDS liblua libiconv libcharsetdetect copy-liboolua libdyncall
	)  