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

    explicit String(const char chars[]);

    explicit String(const String& string);

    explicit String(const char c);

    explicit String(const int i);

    explicit String(const float f);

    explicit String(const bool b);

    ~String();

    size_t length() const;
    void print() const;
    const char & charAt(int i) const;
    const char* getContent() const;
    bool equals(String* s) const;

    String& concat(String& s);
    String& concat(const char *s);
    String& append(String *s);
    String& append(const char *s);
    bool equals(const char* c) const;
    bool equals(const String& s) const;
    String& setContent(char chars[]);
    String& setContent(String* string);
    String& setInputAsContent();
    String& substring(int i, int j);

    friend String& operator+(const String & s1, const String & s2);
    friend String& operator+(const String & s1, const char * c2);
    friend String& operator+(const char * c1, const String & s2);

    String& operator+=(const String & s1);
    String& operator+=(const char * c1);

    bool operator==(const String & s1) const;
    bool operator==(const char * c1) const;

    String& operator=(const String & s1);
    String& operator=(const char * c1);

    friend std::ostream& operator<<(std::ostream & out,const String& s1);
    friend std::istream& operator>>(std::istream & in, String& s1);

    char operator[](const int i) const;
    char& operator[](const int i);

};


#endif //POO2LABSTRING_CSTRING_H
