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

    
    return 0;
}
