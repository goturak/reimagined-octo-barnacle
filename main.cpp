#include <iostream>
#include "cstring.hpp"

int main() {
    /**
     * Test constructors, getLength, and operator <<
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

    std::cout << " ================ TEST CONSTRUCTOR ================ " << std::endl;
    std::cout << empty << " " << empty.getLength() << std::endl;
    std::cout << sChars << " " << sChars.getLength() << std::endl;
    std::cout << sString << " " << sString.getLength() << std::endl;
    std::cout << sInt << " " << sInt.getLength() << std::endl;
    std::cout << sDouble << " " << sDouble.getLength() << std::endl;
    std::cout << sBool << " " << sBool.getLength() << std::endl;
    std::cout << sChar << " " << sChar.getLength() << std::endl;

    /**
     * Test print
     */
    std::cout << " ================ TEST PRINT ================ " << std::endl;
    sChars.print();
    std::cout << std::endl;

    /**
     * Test charAt
     */
    char c2 = sChars.charAt(2);
    std::cout << " ================ TEST CHARAT ================ " << std::endl;
    std::cout << c2 << std::endl;

    /**
     * Test append
     */
    sChars.append(sInt);
    sChars.append("07");
    std::cout << " ================ TEST APPEND ================ " << std::endl;
    std::cout << sChars << std::endl;

    /**
     * Test copy constructor makes content reference different
     */
    std::cout << " ================ TEST COPY CONSTRUCTOR ================ " << std::endl;
    std::cout << sChars << " / " << sString << std::endl;

    /**
     * Test concat and operator =
     */
    empty = sChars.append(sInt);
    empty = empty.append("07");
    std::cout << " ================ TEST CONCAT AND = ================ " << std::endl;
    std::cout << empty << std::endl;

    /**
     * Test substring and equals
     */
    std::cout << " ================ TEST SUBSTRING AND EQUALS ================ " << std::endl;
    String isSame = String(empty.equals(sChars));
    std::cout << isSame << std::endl;
    empty = empty.substring(0, 18);
    isSame = String(empty.equals(sChars));
    std::cout << isSame << std::endl;

    /**
     * Test setInputAsContent
     */
    std::cout << " ================ TEST SET INPUT AS CONTENT ================ " << std::endl;
    std::cout << "Enter a string: " << std::endl;
    empty.setInputAsContent();
    std::cout << "You entered this: \"" << empty << "\", de longueur " << empty.getLength() << std::endl;

    /**
     * Test operator +
     */
    std::cout << " ================ TEST OPERATOR + ================ " << std::endl;
    String newString1 = sBool + sDouble;
    String newString2 = sBool + " test success1 ";
    String newString3 = " test success2 " + sBool;
    std::cout << newString1 << " / " << newString2 << " / " <<  newString3 << std::endl;

    /**
     * Test operator +=
     */
    std::cout << " ================ TEST OPERATOR += ================ " << std::endl;
    newString2 += sChar;
    newString2 += "h!";
    std::cout << newString2 << std::endl;

    /**
     * Test operator == and >>
     */
    std::cout << " ================ TEST OPERATOR == and >> ================ " << std::endl;
    std::cout << "Enter two time the same string: ";
    std::cin >> newString1;
    std::cin >> newString2;
    std::cout << String(newString1 == newString2) << std::endl;
    std::cout << "Enter two different strings: ";
    std::cin >> newString1;
    std::cin >> newString2;
    std::cout << String(newString1 == newString2) << std::endl;

    /**
     * Test operator []
     */
    std::cout << " ================ TEST OPERATOR [] ================ " << std::endl;
    std::cout << array[10] << " " << array[11] << " " << array[12] << " " << array[13] << std::endl;

    return 0;
}