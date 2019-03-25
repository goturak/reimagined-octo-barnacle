#include <cstdlib>
#include <cstring>
#include <iostream>
#include "cstring.h"

String::String():content("\0"){}

String::String(char chars[]):content(chars){}

String::String(String* string):content(string->content){}

String::String(char c){}

String::String(int i){}

String::String(float f){}

String::String(bool b){}

int String::length() { return std::strlen(content);}

void String::print() {
    for(int i = 0; i< this->length();i++){
        std::cout << content[i];
    }
}

char & String::charAt(int i){
    if(i>=length()){
        throw "index of of bound!";
    }else{
        return const_cast<char &>(content[i]);
    }
}