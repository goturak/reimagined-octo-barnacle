#include <iostream>
#include "cstring.hpp"

int main() {
    /**
     * Test des constructeurs et de getLength
     */
    char array[] = "This is a test";
    int i = 0;
    float d = 2.0;
    bool b = true;
    char c = 'a';

    String empty = String();
    String sChars = String(array);
    String sString = String(sChars);
    String sDouble = String(d);
    String sInt = String(i);
    String sBool = String(b);
    String sChar = String(c);

    std::cout << " ================TEST CONSTRUCTOR================ " << std::endl;
    std::cout << empty << " " << empty.getLength() << std::endl;
    std::cout << sChars << " " << sChars.getLength() << std::endl;
    std::cout << sString << " " << sString.getLength() << std::endl;
    std::cout << sInt << " " << sInt.getLength() << std::endl;
    std::cout << sDouble << " " << sDouble.getLength() << std::endl;
    std::cout << sBool << " " << sBool.getLength() << std::endl;
    std::cout << sChar << " " << sChar.getLength() << std::endl;

    /**
     * Test de print
     */
    std::cout << " ================TEST PRINT================ " << std::endl;
    sChars.print();
    std::cout << std::endl;

    /**
     * Test charAt
     */
    char c2 = sChars.charAt(2);
    std::cout << " ================TEST CHARAT================ " << std::endl;
    std::cout << c2 << std::endl;

    /**
     * Test append
     */
     sChars.append(sInt);
     sChars.append("07");
    std::cout << " ================TEST APPEND================ " << std::endl;
    std::cout << sChars << std::endl;

    /**
     * Test copy constructor makes content reference different
     */
    std::cout << " ================TEST COPY CONSTRUCTOR================ " << std::endl;
    std::cout << sChars << " / " << sString << std::endl;

     /**
      * Test concat and operator =
      */
     empty = sChars.append(sInt);
     empty = empty.append("07");
    std::cout << " ================TEST CONCAT AND = ================ " << std::endl;
    std::cout << empty << std::endl;

     /**
      * Test substring and equals
      */
      std::cout << " ================TEST SUBSTRING AND EQUALS================ " << std::endl;
      String isSame = String(empty.equals(sChars));
      std::cout << isSame << std::endl;
      empty = empty.substring(0,15);
      isSame = String(empty.equals(sChars));
      std::cout << isSame << std::endl;


    return 0;
}