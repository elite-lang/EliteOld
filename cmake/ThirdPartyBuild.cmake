if(UNIX)
	include(/usr/share/cmake/Modules/ExternalProject.cmake)
endif()

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

ADD_CUSTOM_TARGET(deps
	DEPENDS liblua libiconv libcharsetdetect)



ADD_CUSTOM_TARGET(copy-deps
	COMMAND 
	DEPENDS liblua libiconv libcharsetdetect

	)