#include <iostream>
#include "cstring.hpp"

int main() {
    /**
     * Test des constructeurs
     */
    char array[] = "This is a test";
    int i = 0;
    float d = 2.0;
    bool b = true;
    char c = 'a';

    String* empty = new String();
    String* sChars = new String(array);
    String* sString = new String(*sChars);
    String* sDouble = new String(d);
    String* sInt = new String(i);
    String* sBool = new String(b);
    String* sChar = new String(c);

    std::cout << empty->getContent() << " " << empty->getLength() << std::endl;
    std::cout << sChars->getContent() << " " << sChars->getLength() << std::endl;
    std::cout << sString->getContent() << " " << sString->getLength() << std::endl;
    std::cout << sInt->getContent() << " " << sInt->getLength() << std::endl;
    std::cout << sDouble->getContent() << " " << sDouble->getLength() << std::endl;
    std::cout << sBool->getContent() << " " << sBool->getLength() << std::endl;
    std::cout << sChar->getContent() << " " << sChar->getLength() << std::endl;

    /**
     * Test du constructeur de copie
     */
    



    return 0;
}