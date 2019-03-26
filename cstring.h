//
// Created by goturak on 25/03/19.
//

#ifndef POO2LABSTRING_CSTRING_H
#define POO2LABSTRING_CSTRING_H


class String {
private:
    char * content;
public:


public:
    explicit String();

    explicit String(char chars[]);

    explicit String(String* string);

    explicit String(char c);

    explicit String(int i);

    explicit String(float f);

    explicit String(bool b);

    int length();
    void print();
    char & charAt(int i);
    const char* getContent();
    bool equals(String* s);

    String concat(String *s);
    String concat(const char *s);
    void append(String *s);
    void append(const char *s);

    bool equals(char* s);
    void setContent(char chars[]);
    void setContent(String* string);
    void setInputAsContent();
    String substring(int i, int j);

};


#endif //POO2LABSTRING_CSTRING_H
