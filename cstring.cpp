#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include "cstring.hpp"

/**
 * Constructor of empty String
 */
String::String() {
    content = new char[1];
    content[0] = '\0';
    length = 0;
}

/**
 * Destructor of the string
 */
String::~String() {
    delete[](content);
}

/**
 * Constructor with a char array as parameter
 * @param chars the chars that make a string
 */
String::String(const char chars[]) {
    length = strlen(chars);
    content = new char[length];
    strcpy(content, chars);
}

/**
 * Copy constructor
 * @param string the other string we want to copy.
 */
String::String(const String &string) {
    length = string.getLength();
    content = new char[length];
    strcpy(content, string.getContent());
}

/**
 * Constructor taking a single character
 * @param c the character we make a string with
 */
String::String(const char c) {
    length = 1;
    content = new char[2];
    content[0] = c;
    content[1] = '\0';
}

/**
 * Constructor taking an int
 * @param i the int we make a string with
 */
String::String(const int i) {
    content = new char[255];
    length = sprintf(content, "%d", i);
}

/**
 * Constructor taking a double
 * @param f the float we want to make a string with
 */
String::String(const double d) {
    content = new char[255];
    length = sprintf(content, "%lf", d);
}

/**
 * Constructor taking a boolean
 * @param b the boolean we want to make a string with
 */
String::String(const bool b) {
    if (b) {
        char array[] = "true";
        length = 4;
        content = new char[length];
        strcpy(content, array);
    } else {
        char array[] = "false";
        length = 5;
        content = new char[length];
        strcpy(content, array);
    }

}

/**
 * Method returning the length of the string
 * @return the length of the current string
 */
size_t String::getLength() const {
    return length;
}

/**
 * Print method
 */
void String::print() const {
    for (int i = 0; i < length; i++) {
        std::cout << content[i];
    }
}

/**
 * The method used to get a char in a specific index of the string
 * @param i the index of the char
 * @return the char at the index
 */
const char &String::charAt(const int i) const {
    if (i >= length) {
        throw "index of of bound!";
    } else {
        return content[i];
    }
}

/**
 * content getter
 * @return content
 */
const char *String::getContent() const {
    return content;
}

/**
 * compares a String with another
 * @param s the second string
 * @return whether they are equal or not
 */
bool String::equals(const String &s) const {
    if (s.getLength() == length) {
        for (int i = 0; i < length; i++) {
            if (s.getContent()[i] != getContent()[i]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

/**
 * compares a String with a const char*
 * @param s the second string
 * @return whether they are equal or not
 */
bool String::equals(const char *s) const {
    if (std::strlen(s) == length) {

        for (int i = 0; i < length; i++) {
            if (s[i] != getContent()[i]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }

}

/**
 * appends a String
 * @param s the String to append
 * @return this string concatenate with s
 */
String &String::append(const String &s) {
    int totalLen = length + s.getLength();

    char newContent[totalLen];

    std::strcpy(newContent, getContent());
    std::strcat(newContent, s.getContent());

    return setContent(newContent);
}

/**
 * appends a const char s
 * @param s the const char to append
 * @return this string concatenate to s
 */
String &String::append(const char *s) {
    int totalLen = length + std::strlen(s);

    char newContent[totalLen];

    std::strcpy(newContent, getContent());
    std::strcat(newContent, s);

    return setContent(newContent);
}

/**
 * Setter of the content taking a char array.
 * @param chars the new content of the string.
 * @return this
 */
String &String::setContent(const char *chars) {
    if (!(chars == content)) {
        delete[](content);
        content = new char[strlen(chars)];
        strcpy(content, chars);
        length = strlen(chars);
        return *this;
    } else {
        return *this;
    }
}

/**
 * Setter of the content taking a char array.
 * @param chars the new content of the string.
 * @return this
 */
String &String::setContent(const String &string) {
    return String::setContent(string.content);
}

/**
 * Method used to make a subset of the string from one index to another
 * @param i the starting index of the string
 * @param j the ending index of the string (exclusive)
 * @return the new string created with this method.
 */
String &String::substring(int i, int j) const {
    if (i < j) {
        char *chars = new char[j - i];
        for (int k = 0; k < j - i; k++) {
            chars[k] = charAt(k + i);
        }
        String *result = new String(chars);
        return *result;
    } else {
        String *result = new String();
        return *result;
    }

}

/**
 * Setter that take the input of the user to set the new content of the string
 * @return this
 */
String &String::setInputAsContent() {
    char chars[255];
    scanf("%[^\n]%*c", chars);
    return setContent(chars);
}

/**
 * Override of the + operator
 * @param s1 left operand
 * @param s2 right operand
 * @return s1 concatenate with s2
 */
String &operator+(const String &s1, const String &s2) {
    String *result = new String(s1);
    return result->append(s2);
}

/**
 * Override of the + operator
 * @param s left operand
 * @param c right operand
 * @return s concatenate with c
 */
String &operator+(const String &s, const char *c) {
    String *result = new String(s);
    return result->append(c);
}

/**
 * Override of the + operator
 * @param c left operand
 * @param s right operand
 * @return c concatenate with c
 */
String &operator+(const char *c, const String &s) {
    String *result = new String(c);
    return result->append(s);
}

/**
 * Override of the += operator
 * @param s right operand
 * @return this concatenate with s
 */
String &String::operator+=(const String &s) {
    return append(s);
}

/**
 * Override of the += operator
 * @param c right operand
 * @return this concatenate with c
 */
String &String::operator+=(const char *c) {
    return append(c);
}

/**
 * Override of the == operator
 * @param s right operand
 * @return true if this is equal to s, false otherwise
 */
bool String::operator==(const String &s) const {
    return equals(s);
}

/**
 * Override of the == operator
 * @param c right operand
 * @return true if this is equal to c, false otherwise
 */
bool String::operator==(const char *c) const {
    return equals(c);
}

/**
 * Override of the = operator
 * @param s the right operand
 * @return a copy of s
 */
String &String::operator=(const String &s) {
    return setContent(s);
}

/**
 * Override of the = operator
 * @param c the right operand
 * @return a string containing c
 */
String &String::operator=(const char *c) {
    return setContent(c);
}

/**
 * Override of the << operator
 * @param out the output stream
 * @param s the string to display
 * @return the output stream containing the string's display
 */
std::ostream &operator<<(std::ostream &out, const String &s) {
    return out << s.content;
}

/**
 * Override of the >> operator
 * @param in the input stream
 * @param s the string containing the user's input
 * @return the input stream containing the string of the user.
 */
std::istream &operator>>(std::istream &in, String &s) {
    char *chars = new char[255];
    in >> chars;
    s.setContent(chars);
    return in;
}

/**
 * Override of the [] operator
 * @param i the index of the char that we want
 * @return the char that is at the index i
 */
const char &String::operator[](const int i) const {
    return charAt(i);
}

