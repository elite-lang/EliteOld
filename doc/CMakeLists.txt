FIND_PACKAGE(Doxygen)
OPTION(BUILD_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" ${DOXYGEN_FOUND})

IF(BUILD_DOCUMENTATION)
    IF(NOT DOXYGEN_FOUND)
        MESSAGE(FATAL_ERROR "Doxygen is needed to build the documentation.")
    ENDIF()

    CONFIGURE_FILE(Doxyfile.in Doxyfile @ONLY)
    CONFIGURE_FILE(Doxyfile.zh-cn.in Doxyfile.zh-cn @ONLY)

    file(GLOB_RECURSE MARKDOWN_DOC ${PROJECT_SOURCE_DIR}/doc/*.md)

    add_custom_command(OUTPUT html
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.zh-cn
        DEPENDS ${MARKDOWN_DOC} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile*
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        )

    ADD_CUSTOM_TARGET(doc
        ALL DEPENDS html
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)

    INSTALL(DIRECTORY ${PROJECT_SOURCE_DIR}/build-doc/html DESTINATION doc COMPONENT doc)
ENDIF()
