

ADD_CUSTOM_TARGET(header
    COMMAND ${CMAKE_COMMAND} -E copy_directory ../ExIconv/include header
    COMMAND ${CMAKE_COMMAND} -E copy_directory ../Lex/include header
    COMMAND ${CMAKE_COMMAND} -E copy_directory ../LR_Scanner/includes header
    COMMAND ${CMAKE_COMMAND} -E copy_directory ../RedApple/includes header
    COMMAND ${CMAKE_COMMAND} -E copy_directory ../Builder/include header
    COMMAND ${CMAKE_COMMAND} -E copy_directory ../MetaScriptRunner/include header
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating headers"
    VERBATIM)

    install(DIRECTORY
            ${CMAKE_CURRENT_SOURCE_DIR}/build/header
            DESTINATION .
            FILE_PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
            GROUP_EXECUTE GROUP_READ WORLD_READ
            DIRECTORY_PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
            GROUP_EXECUTE GROUP_READ WORLD_READ
            COMPONENT header
            PATTERN ".git" EXCLUDE)
