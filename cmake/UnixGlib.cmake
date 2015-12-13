find_package(PkgConfig)
pkg_check_modules(GLIBMM glibmm-2.4 giomm-2.4)
link_directories(${GLIBMM_LIBRARY_DIRS})
include_directories(${GLIBMM_INCLUDE_DIRS})