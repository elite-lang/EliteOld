
set(InstallLocation /opt/Elite)

FILE(GLOB bin_files elite)
FILE(GLOB_RECURSE conf_files *)
FILE(GLOB_RECURSE packages_files *)
FILE(GLOB_RECURSE tools_files ${CMAKE_CURRENT_SOURCE_DIR}/tools/*)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
DESTINATION ${InstallLocation})
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/conf
        DESTINATION ${InstallLocation})
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/packages
        DESTINATION ${InstallLocation}
        PATTERN ".git" EXCLUDE)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tools
        DESTINATION ${InstallLocation}
        PATTERN ".git" EXCLUDE)
