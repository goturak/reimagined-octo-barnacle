#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
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


char & String::charAt(int i){
    if(i>=length()){
        throw "index of of bound!";
    }else{
        return const_cast<char &>(content[i]);
    }
}
/**
 * content getter
 * @return content
 */
const char* String::getContent(){
    return content;
}
/**
 * compares a String with another
 * @param s the second string
 * @return whether they are equal or not
 */
bool String::equals(String* s) {
    if(s->length()&&this->length()){

        for(int i = 0; i< this->length();i++){
            if(s->getContent()[i]!=this->getContent()[i]){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }

}

/**
 * compares a String with a const char*
 * @param s the second string
 * @return whether they are equal or not
 */
bool String::equals(const char *s) {
    if(std::strlen(s)&&this->length()){

        for(int i = 0; i< this->length();i++){
            if(s[i]!=this->getContent()[i]){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }

}

