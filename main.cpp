#include <iostream>
#include "cstring.h"

int main() {
    char array[] = "One, good, thing, about, music";
    char array2[] = "Celui qui lit ça est un con.";
    String* test= new String(array2);
    String* con = new String(array2);
    test->charAt(2)= '4';
    test->setContent(array);
    test->print();
    test->setContent(con);
    con->charAt(2) = '4';
    test->print();
    con->print();

    return 0;
}