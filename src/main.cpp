// Copyright 2024 by Contributors
#include "../include/MyString.h"

int main() {
    MyString sToMove("move");  // const char*
    MyString s0("abc");  // const char*
    std::string str = "Hello,";

    MyString s1(str);  // std::string
    std::cout << s1 << std::endl;  // Hello,

    MyString s2("world!");
    MyString s12423(std::move(sToMove));  // move-constructor
    std::cout << s12423 << std::endl;  // move

    MyString s12443(s0);  // copy-constructor
    std::cout << s12443 << std::endl;  // abc

    MyString s3;
    s3 = s1 + s2;

    std::cout << s3 << std::endl;  // Hello,world!
    std::cout << s3.length() << std::endl;  // 12
    std::cout << s3((MyString)"ll") << std::endl;  // 2
    std::cout << s3((MyString)"mama") << std::endl;  // -1

    MyString s6("abbaxxca");
    MyString s4 = s0 * 3;
    MyString s104 = s6 - s0;

    std::cout << "s6 - s0: " << s104 << std::endl;  // xx
    std::cout << "s1 * 3: " << s4 << std::endl;  // abcabcabc

    std::cout << "s1 == s2: " << (s1 == s2) << std::endl;  // false
    std::cout << "s1 != s2: " << (s1 != s2) << std::endl;  // true
    std::cout << "s1 > s2: " << (s1 > s2) << std::endl;    // false
    std::cout << "s1 < s2: " << (s1 < s2) << std::endl;    // true
    std::cout << "s1 >= s2: " << (s1 >= s2) << std::endl;  // false
    std::cout << "s1 <= s2: " << (s1 <= s2) << std::endl;  // true

    std::cout << "!s0: " << !s0 << std::endl;  // ABC
    std::cout << "s0[0]: " << s0[0] << std::endl;  // a

    MyString s5;
    std::cout << "Enter a string: ";
    std::cin >> s5;
    std::cout << "s5: " << s5 << std::endl;

    MyString s123706;
    s123706 = (MyString)"blablabla";
    std::cout << s123706 << std::endl;  // blablabla

    std::cout << s0.get() << std::endl;  // abc

    MyString str1 = (MyString)"Meow";
    MyString str2 = (MyString)"Foo";
    MyString str3 = (MyString)"Woops";
    str1 = str2 + str3 + (MyString)"Baz";

    std::cout << str1  << std::endl;
    return 0;
}
