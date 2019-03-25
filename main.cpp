#include <iostream>
#include "cstring.h"

int main() {
    char array[] = "One, good, thing, about, music";
    String* test= new String(array);
    test->print();
    return 0;
}