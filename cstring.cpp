#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include "cstring.hpp"

/**
 * Constructor of empty String
 */
String::String(){
    this->content = (char*)"";
    this->length = 0;
}

String::~String() {}

/**
 * Constructor with a char array as parameter
 * @param chars the chars that make a string
 */
String::String(const char chars[]){
    this->length = strlen(chars);
    this->content = (char*)malloc(this->length);
    std::strcpy(this->content, chars);
}

/**
 * Copy constructor
 * @param string the other string we want to copy.
 */
String::String(const String& string){
    String(string.content);
}

/**
 * Constructor taking a single character
 * @param c the character we make a string with
 */
String::String(const char c){
    this->length = 2;
    char out_string[2];
    out_string[0] = c;
    out_string[1] = '\0';
    this->content = out_string;

}

/**
 * Constructor taking an int
 * @param i the int we make a string with
 */
String::String(const int i){
    char out_string[255];
    sprintf(out_string, "%d", i);
    this->length = strlen(out_string);
    this->content = out_string;
}

/**
 * Constructor taking a float
 * @param f the float we want to make a string with
 */
String::String(const float f){
    char out_string[255];
    sprintf(out_string, "%lf", f);
    this->length = strlen(out_string);
    this->content = out_string;
}

/**
 * Constructor taking a boolean
 * @param b the boolean we want to make a string with
 */
String::String(const bool b){
    if(b){
        this->content = String("true").content;
        this->length = 5;
    } else {
        this->content = String("false").content;
        this->length = 6;
    }

}

/**
 * Method returning the length of the string
 * @return
 */
size_t String::getLength() const {
    return this->length;
}

void String::print() const{
    for(int i = 0; i < this->length;i++){
        std::cout << content[i];
    }
}

/**
 * The method used to get a char in a specific index of the string
 * @param i the index of the char
 * @return the char at the index
 */
const char & String::charAt(int i) const{
    if(i >= length){
        throw "index of of bound!";
    }else{
        return content[i];
    }
}

/**
 * content getter
 * @return content
 */
const char* String::getContent() const{
    return content;
}

/**
 * compares a String with another
 * @param s the second string
 * @return whether they are equal or not
 */
bool String::equals(const String& s) const{
    if(s.getLength() && this->length){
        for(int i = 0; i < this->length;i++){
            if(s.getContent()[i]!=this->getContent()[i]){
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
bool String::equals(const char *s) const{
    if(std::strlen(s)&&this->length){

        for(int i = 0; i < this->length;i++){
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
 * appends a String in place
 * @param s the String to append
 */
void String::append(const String& s){
    int totalLen = this->length + s.getLength();

    char newContent[totalLen+1];

    std::strcpy(newContent,this->getContent());                    //ON VERRA SI ON CHANGE LE TRUC OU PAS
    std::strcat(newContent,s.getContent());

    this->setContent(newContent);
}

/**
 * appends a const char s in place
 * @param s the const char to append
 */
void String::append(const char* s){
    int totalLen = this->length + std::strlen(s);

    char newContent[totalLen+1];

    std::strcpy(newContent,this->getContent());
    std::strcat(newContent,s);

    this->setContent(newContent);
}

/**
 * Setter of the content taking a char array.
 * @param chars the new content of the string.
 */
String& String::setContent(const char* chars){
    free(this->content);
    this->content = (char*)malloc(strlen(chars));
    strcpy(this->content, chars);
    return *this;
}

/**
 * Setter of the content taking a char array.
 * @param chars the new content of the string.
 */
String& String::setContent(const String& string){
    return String::setContent(string.content);
}

/**
 * Method used to make a subset of the string from one index to another
 * @param i the starting index of the string
 * @param j the ending index of the string (exclusive)
 * @return the new string created with this method.
 */
String& String::substring(int i, int j) const{
    char chars[j-i];
    for(int k = 0; k < j-i; k++){
        chars[k] = this->charAt(k+i);
    }
    return *(new String(chars));

}

/**
 * concatenates a String s and returns a new String
 * @param s the String to concatenate
 */
String& String::concat(const String& s){
    int totalLen = this->length + s.getLength();

    char newContent[totalLen+1];

    std::strcpy(newContent,this->getContent());
    std::strcat(newContent,s.getContent());

    return this->setContent(newContent);

}

/**
 * concatenates a const char s and returns a new String
 * @param s the const char to concatenate
 */
String& String::concat(const char* s){
    int totalLen = this->length + std::strlen(s);

    char newContent[totalLen+1];

    std::strcpy(newContent,this->getContent());
    std::strcat(newContent,s);

    return this->setContent(newContent);

}

/**
 * Setter that take the input of the user to set the new content of the string
 */
String& String::setInputAsContent(){
    char chars[255];
    scanf("%[^\n]%*c", chars);
    return this->setContent(chars);
}

String& operator+(const String& s1, const String& s2){
    String* result = new String(s1);
    return result->concat(s2);
}
String& operator+(const String & s, const char * c){
    String* result = new String(s);
    return result->concat(c);
}
String& operator+(const char * c, const String & s){
    String* result = new String(s);
    return result->concat(c);
}

String& String::operator+=(const String & s){
    return this->concat(s);
}
String& String::operator+=(const char * c){
    return this->concat(c);
}

bool String::operator==(const String & s) const{
    return this->equals(s);
}
bool String::operator==(const char * c) const{
    return this->equals(c);
}

String& String::operator=(const String & s){
    this->setContent(s);
    return *this;
}
String& String::operator=(const char * c){
    this->setContent(c);
    return *this;
}

std::ostream& operator<<(std::ostream & out,const String& s){
    out << s.getContent();
    return out;
}
std::istream& operator>>(std::istream & in, String& s){
    char chars [255];
    in >> chars;
    s.setContent(chars);
    return in;
}

char String::operator[](const int i) const{
    return charAt(i);
}

