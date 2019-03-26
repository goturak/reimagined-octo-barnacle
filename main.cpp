#include <iostream>
#include "cstring.h"

int main() {
    char array[] = "One, good, thing, about, music";
    char array2[] = "Eat Shit and Die";
    String* test= new String(array);

    //test->charAt(2)= '4';
    std::cout<< test->equals(array2)<<std::endl;
    // printf(test->getContent());
    String* empty= new String(array);
    int bite= empty->length();
   // test->append(array2);

    String tes2t= test->concat(array2);
    tes2t.print();
    return 0;
}