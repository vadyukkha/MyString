// Copyright 2024 by Contributors
#pragma once
#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

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

    MyString operator+(const MyString& other) const;
    MyString operator-(const MyString& other) const;
    MyString operator*(const uint32_t n) const;

    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;

    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator>=(const MyString& other) const;
    bool operator<=(const MyString& other) const;

    MyString operator!() const;
    char& operator[](const size_t index) const;
    int64_t operator()(const MyString& substr) const;

    friend std::istream& operator>>(std::istream& is, MyString& obj);
    friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
};

#endif  // INCLUDE_MYSTRING_H_
