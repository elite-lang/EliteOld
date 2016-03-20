#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include "lua.hpp"
#include <string>

class Preprocessor {
public:
    Preprocessor (const std::string& input, lua_State* L);
    virtual ~Preprocessor ();

    const std::string& genCode();
    const std::string& runCode();

    std::string output;
    const std::string& input;
    std::string code_string;
protected:
    lua_State* L;

    int add_const_str(std::string::const_iterator p, std::string::const_iterator q);
    int pt_size = 0;

};




#endif /* end of include guard: PREPROCESSOR_H */
