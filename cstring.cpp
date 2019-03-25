#include <cstdlib>
#include <cstdio>
#include "cstring.h"

String::String():content("\0"){}

String::String(char chars[]):content(chars){}

String::String(String* string):content(string->content){}

String::String(char c):content(){
    char out_string[2];
    out_string[0] = c;
    out_string[1] = '\0';
    this->content = out_string;

}

String::String(int i){
    char out_string[20];
    sprintf(out_string, "%d", i);
    this->content = out_string;
}

String::String(float f){
    char out_string[20];
    sprintf(out_string, "%lf", f);
    this->content = out_string;
}

String::String(bool b){
    if(b){
        this->content = String("true").content;
    } else {
        this->content = String("false").content;
    }

}

int String::length() { return std::strlen(content);}

void String::print() {
    for(int i = 0; i< this->length();i++){
        std::cout << content[i];
    }
}
