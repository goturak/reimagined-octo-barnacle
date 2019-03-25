#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>

#include "cstring.h"

/**
 * Constructor of the empty string
 */
String::String():content("\0"){}

/**
 * Constructor with a char array as parameter
 * @param chars the chars that make a string
 */
String::String(char chars[]){
    this->content = (char*)malloc(40);
    std::strcpy(this->content, chars);

}

/**
 * Copy constructor
 * @param string the other string we want to copy.
 */
String::String(String* string){
    String(string->content);
}

/**
 * Constructor taking one character.
 * @param c The character we want to make the string with.
 */
String::String(char c):content(){
    char out_string[2];
    out_string[0] = c;
    out_string[1] = '\0';
    this->content = out_string;

}

/**
 * Constructor taking an integer.
 * @param i the integer we want to represent as string.
 */
String::String(int i){
    char out_string[20];
    sprintf(out_string, "%d", i);
    this->content = out_string;
}

/**
 * Constructor taking a float
 * @param f The float we want to represent as string.
 */
String::String(float f){
    char out_string[20];
    sprintf(out_string, "%lf", f);
    this->content = out_string;
}

/**
 * Constructor taking a boolean.
 * @param b the bool we want to represent as string.
 */
String::String(bool b){
    if(b){
        char tarray[5] = "true";
        this->content = tarray;
    } else {
        char farray[6] = "false";
        this->content = farray;
    }

}

int String::length() { return std::strlen(content);}

void String::print() {
        std::cout << content;
}


char & String::charAt(int i){
    if(i>=length()){
        throw "index of of bound!";
    }else{
        return const_cast<char &>(content[i]);
    }
}

/**
 * Setter of the content taking a char array.
 * @param chars the new content of the string.
 */
void String::setContent(char chars []){
    free(this->content);
    this->content = (char*)malloc(40);
    strcpy(this->content, chars);
}

/**
 * Setter of the content taking a char array.
 * @param chars the new content of the string.
 */
void String::setContent(String* string){
    String::setContent(string->content);
}


