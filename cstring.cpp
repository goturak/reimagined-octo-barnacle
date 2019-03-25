#include <cstdlib>
#include "cstring.h"

String::String():content("\0"){}

String::String(char chars[]):content(chars){}

String::String(String* string):content(string->content){}

String::String(char c):content((char*)c){}

String::String(int i):content(i){}

String::String(float f):content(f){}

String::String(bool b){}
