//
// Created by goturak on 25/03/19.
//

#ifndef POO2LABSTRING_CSTRING_H
#define POO2LABSTRING_CSTRING_H


class String {
private:
public:
    char * content;

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
    bool equals(char* s);
    void setContent(char chars[]);
    void setContent(String* string);
};


#endif //POO2LABSTRING_CSTRING_H
