#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include "cstring.h"

String::String():content(""){}


/**
 * Constructor with a char array as parameter
 * @param chars the chars that make a string
 */
String::String(char chars[]){
    this->content = (char*)malloc(strlen(chars));
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
 * Constructor taking a single character
 * @param c the character we make a string with
 */
String::String(char c):content(){
    char out_string[2];
    out_string[0] = c;
    out_string[1] = '\0';
    this->content = out_string;

}

/**
 * Constructor taking an int
 * @param i the int we make a string with
 */
String::String(int i){
    char out_string[20];
    sprintf(out_string, "%d", i);
    this->content = out_string;
}

/**
 * Constructor taking a float
 * @param f the float we want to make a string with
 */
String::String(float f){
    char out_string[20];
    sprintf(out_string, "%lf", f);
    this->content = out_string;
}

/**
 * Constructor taking a boolean
 * @param b the boolean we want to make a string with
 */
String::String(bool b){
    if(b){
        this->content = String("true").content;
    } else {
        this->content = String("false").content;
    }

}

/**
 * Method returning the length of the string
 * @return
 */
int String::length() { return std::strlen(content);}

void String::print() {
    for(int i = 0; i< this->length();i++){
        std::cout << content[i];
    }
}

/**
 * The method used to get a char in a specific index of the string
 * @param i the index of the char
 * @return the char at the index
 */
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
bool String::equals(char *s) {
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

/**
 * Setter of the content taking a char array.
 * @param chars the new content of the string.
 */
void String::setContent(char chars []){
    free(this->content);
    this->content = (char*)malloc(strlen(chars));
    strcpy(this->content, chars);
}

/**
 * Setter of the content taking a char array.
 * @param chars the new content of the string.
 */
void String::setContent(String* string){
    String::setContent(string->content);
}

/**
 * Method used to make a subset of the string from one index to another
 * @param i the starting index of the string
 * @param j the ending index of the string (exclusive)
 * @return the new string created with this method.
 */
String String::substring(int i, int j){
    char chars[j-i];
    for(int k = 0; k < j-i; k++){
        chars[k] = this->charAt(k+i);
    }
    return *(new String(chars));

}



