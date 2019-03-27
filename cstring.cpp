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

String::~String() {
    delete[](this->content);
}

/**
 * Constructor with a char array as parameter
 * @param chars the chars that make a string
 */
String::String(const char chars[]){
    this->length = strlen(chars);
    this->content = new char[this->length];
    std::strcpy(this->content, chars);
}

/**
 * Copy constructor
 * @param string the other string we want to copy.
 */
String::String(const String& string){
    this->length = string.getLength();
    this->content = (char*)malloc(this->length);
    strcpy(this->content,string.getContent());
}

/**
 * Constructor taking a single character
 * @param c the character we make a string with
 */
String::String(const char c){
    this->length = 1;
    this->content = new char[2];
    this->content[0] = c;
    this->content[1] = '\0';
}

/**
 * Constructor taking an int
 * @param i the int we make a string with
 */
String::String(const int i){
    this->content = new char[255];
    this->length = sprintf(this->content, "%d", i);
}

/**
 * Constructor taking a double
 * @param f the float we want to make a string with
 */
String::String(const double d){
    this->content = new char[255];
    this->length = sprintf(this->content, "%lf", d);
}

/**
 * Constructor taking a boolean
 * @param b the boolean we want to make a string with
 */
String::String(const bool b){
    if(b){
        this->content = "true";
        this->length = 4;
    } else {
        this->content = "false";
        this->length = 5;
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
String& String::append(const String& s){
    int totalLen = this->length + s.getLength();

    char newContent[totalLen];

    std::strcpy(newContent,this->getContent());                    //ON VERRA SI ON CHANGE LE TRUC OU PAS
    std::strcat(newContent,s.getContent());

    return this->setContent(newContent);
}

/**
 * appends a const char s in place
 * @param s the const char to append
 */
String& String::append(const char* s){
    int totalLen = this->length + std::strlen(s);

    char newContent[totalLen];

    std::strcpy(newContent,this->getContent());
    std::strcat(newContent,s);

    return this->setContent(newContent);
}

/**
 * Setter of the content taking a char array.
 * @param chars the new content of the string.
 */
String& String::setContent(const char* chars){
    delete[](this->content);
    this->content = (char*)malloc(strlen(chars));
    strcpy(this->content, chars);
    this->length = strlen(chars);
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
 * Setter that take the input of the user to set the new content of the string
 */
String& String::setInputAsContent(){
    char chars[255];
    scanf("%[^\n]%*c", chars);
    return this->setContent(chars);
}

String& operator+(const String& s1, const String& s2){
    String* result = new String(s1);
    return result->append(s2);
}
String& operator+(const String & s, const char * c){
    String* result = new String(s);
    return result->append(c);
}
String& operator+(const char * c, const String & s){
    String* result = new String(s);
    return result->append(c);
}

String& String::operator+=(const String & s) {
    return this->append(s);
}

String& String::operator+=(const char * c){
    return this->append(c);
}

bool String::operator==(const String & s) const{
    return this->equals(s);
}
bool String::operator==(const char * c) const{
    return this->equals(c);
}

String& String::operator=(const String & s){
    if(this->content == s.getContent()){
        return *this;
    }
    if(this->getLength() != s.getLength()){
        if(this->content != "") {
            delete[](this->content);
        }
        this->content = new char [s.getLength()];
    }
    strcpy(this->content, s.getContent());
    return *this;
}
String& String::operator=(const char * c){
    if(this->getLength() != strlen(c)){
        delete[](this->content);
        this->content = new char [strlen(c)];
    }
    strcpy(this->content, c);
    return *this;
}

std::ostream& operator<<(std::ostream & out, const String& s){
    return out << s.content;
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

