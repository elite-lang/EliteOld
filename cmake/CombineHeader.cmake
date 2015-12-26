

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
