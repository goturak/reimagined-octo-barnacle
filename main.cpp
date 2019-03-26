#include <iostream>
#include "cstring.h"

int main() {
    char array[] = "One, good, thing, about, music";
    char array2[] = "One, goos, thing, about, music";
    String* test= new String(array);
    String* tes2t= new String(array2);
    //test->charAt(2)= '4';
    std::cout<< test->equals(array2)<<std::endl;
   // printf(test->getContent());
    test->print();
    tes2t->print();
    std::cout << std::endl;
    test->substring(1,6).print();
    test->setInputAsContent();
    test->print();
    return 0;
}