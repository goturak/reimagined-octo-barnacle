#include <iostream>
#include "cstring.h"

int main() {
    const char* c = (String("TEST").content);
    char cha = c[5];
    const char* vide = String().content;
    return 0;
}