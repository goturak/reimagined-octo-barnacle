//
// Created by goturak on 25/03/19.
//

#ifndef POO2LABSTRING_CSTRING_H
#define POO2LABSTRING_CSTRING_H


class String {
private:
    size_t length;
    char * content;

public:
    explicit String();

    explicit String(const char chars[]);

    String(const String& string);

    explicit String(const char c);

    explicit String(const int i);

    explicit String(const double d);

    explicit String(const bool b);

    ~String();

    size_t getLength() const;
    const char* getContent() const;
    void print() const;
    const char & charAt(const int i) const;

    String& append(const String& s);
    String& append(const char* s);
    bool equals(const char* c) const;
    bool equals(const String& s) const;
    String& setContent(const char chars[]);
    String& setContent(const String& string);
    String& setInputAsContent();
    String& substring(int i, int j) const;

    friend String& operator+(const String & s1, const String & s2);
    friend String& operator+(const String & s, const char * c);
    friend String& operator+(const char * c, const String & s);

    String& operator+=(const String & s);
    String& operator+=(const char * c);

    bool operator==(const String & s) const;
    bool operator==(const char * c) const;

    String& operator=(const String & s);
    String& operator=(const char * c);

    friend std::ostream& operator<<(std::ostream & out,const String& s);
    friend std::istream& operator>>(std::istream & in, String& s);

    const char & operator[](const int i) const;
};


#endif //POO2LABSTRING_CSTRING_H
