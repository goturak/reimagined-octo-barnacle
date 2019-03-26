//
// Created by goturak on 25/03/19.
//

#ifndef POO2LABSTRING_CSTRING_H
#define POO2LABSTRING_CSTRING_H


class String {
private:
    char * content;
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

    void concat(String* s);
    void concat(const char* s);

    bool equals(char* s);
    void setContent(char chars[]);
    void setContent(String* string);
    String substring(int i, int j);

};


#endif //POO2LABSTRING_CSTRING_H
