// Copyright 2024 by Contributors
#include "../include/MyString.h"

// конструктор с одним параметром
MyString::MyString(const char* input) {
    if (input == nullptr) {
        this->myString = new char[1];
        *this->myString = '\0';
    } else {
        size_t size = strlen(input) + 1;
        this->myString = new char[size];
        snprintf(this->myString, size, "%s", input);
    }
}

// конструктор с одним параметром
MyString::MyString(const std::string& input) {
    size_t size = input.length() + 1;
    this->myString = new char[size];
    snprintf(this->myString, size, "%s", input.c_str());
}

// конструктор копирования
MyString::MyString(const MyString& other) {
    size_t size = strlen(other.myString) + 1;
    this->myString = new char[size];
    snprintf(this->myString, size, "%s", other.myString);
}

// конструктор переноса
MyString::MyString(MyString&& other) noexcept : myString(std::move(other.myString)) {
    other.myString = nullptr;
}

// деструктор
MyString::~MyString() {
    delete[] this->myString;
}

// количество символов (длина строки)
size_t MyString::length() const {
    return strlen(this->myString);
}

// возвращение указателя на данные
char* MyString::get() const {
    return &this->myString[0];
}

// запись в поток
std::ostream& operator<<(std::ostream& os, const MyString& obj) {
    os << obj.myString;
    return os;
}
