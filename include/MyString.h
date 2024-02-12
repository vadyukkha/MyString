// Copyright 2024 by Contributors
#ifndef _USERS_MACBOOK_DOCUMENTS_HSE_C_PROG_MYSTRING_INCLUDE_MYSTRING_H_
#define _USERS_MACBOOK_DOCUMENTS_HSE_C_PROG_MYSTRING_INCLUDE_MYSTRING_H_

#include <cstring>
#include <iostream>
#include <string>

class MyString {
 private:
    char *myString;

 public:
    explicit MyString(const char* input = nullptr);
    explicit MyString(const std::string& input);
    MyString(const MyString& other);
    MyString(MyString&& other) noexcept;
    ~MyString();

    size_t length() const;
    char* get() const;

    friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
};

#endif  // _USERS_MACBOOK_DOCUMENTS_HSE_C_PROG_MYSTRING_INCLUDE_MYSTRING_H_
