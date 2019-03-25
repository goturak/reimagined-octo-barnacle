//
// Created by goturak on 25/03/19.
//

#ifndef POO2LABSTRING_CSTRING_H
#define POO2LABSTRING_CSTRING_H


class String {
private:
public:
    const char * content;

    explicit String();

    explicit String(char chars[]);

    explicit String(String* string);

    explicit String(char c);

    explicit String(int i);

    explicit String(float f);

    explicit String(bool b);

};


#endif //POO2LABSTRING_CSTRING_H
