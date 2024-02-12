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
MyString::MyString(MyString&& st) noexcept : myString(std::move(st.myString)) {
    st.myString = nullptr;
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

// сложение (конкатенация двух строк).
MyString MyString::operator+(const MyString& obj) const {
    MyString newString;
    size_t size = strlen(this->myString) + strlen(obj.myString) + 1;
    newString.myString = new char[size];
    snprintf(newString.myString, size, "%s%s", this->myString, obj.myString);
    return newString;
}

// вычитание (из строки удаляются все символы, присутствующие во 2 строке)
MyString MyString::operator-(const MyString& other) const {
    size_t len1 = strlen(other.myString);
    size_t len2 = strlen(this->myString);
    MyString copyString;

    bool alphabet[256] = { false };

    for (size_t i = 0; i < len1; ++i) {
        alphabet[other.myString[i]] = true;
    }

    size_t currentIndex = 0;
    for (size_t i = 0; i < len2; ++i) {
        if (!alphabet[this->myString[i]]) {
            copyString[currentIndex++] = this->myString[i];
        }
    }
    return copyString;
}

// умножение на целое число (строка повторяется заданное число раз).
MyString MyString::operator*(const uint32_t n) const {
    MyString result;
    size_t size = strlen(this->myString) * n + 1;
    result.myString = new char[size];

    char* ptr = result.myString;
    for (uint32_t i = 0; i < n; ++i) {
        snprintf(ptr, size, "%s", this->myString);
        ptr += strlen(this->myString);
    }

    return result;
}

// копирующее присваивание
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] this->myString;
        size_t size = strlen(other.myString) + 1;
        this->myString = new char[size];
        snprintf(this->myString, size, "%s", other.myString);
    }
    return *this;
}

// перемещающее присваивание
MyString& MyString::operator=(MyString&& other) noexcept {
    if (this != &other) {
        delete[] this->myString;
        this->myString = other.myString;
        other.myString = nullptr;
    }
    return *this;
}

// сравнение на равенство
bool MyString::operator==(const MyString &other) const {
    return strcmp(this->myString, other.myString) == 0;
}

// сравнение на неравенство
bool MyString::operator!=(const MyString &other) const {
    return !(*this == other);
}

// лексографическое сравнение
bool MyString::operator>(const MyString& other) const {
    return strcmp(this->myString, other.myString) > 0;
}

// лексографическое сравнение
bool MyString::operator<(const MyString& other) const {
    return strcmp(this->myString, other.myString) < 0;
}

// лексографическое сравнение
bool MyString::operator>=(const MyString& other) const {
    return !(*this < other);
}

// лексографическое сравнение
bool MyString::operator<=(const MyString& other) const {
    return !(*this > other);
}

// у латинских букв меняется регистр
MyString MyString::operator!() const {
    MyString result = *this;
    uint16_t step = ('a' - 'A');
    char* p = result.myString;
    while (*p != '\0') {
        if ('a' <= *p && *p <= 'z') {
            *p -= step;
        } else if ('A' <= *p && *p <= 'Z') {
            *p += step;
        }
        p++;
    }
    return result;
}

// доступ к символу по индексу
char& MyString::operator[](const size_t index) const {
    return this->myString[index];
}

// поиск подстроки
int64_t MyString::operator()(const MyString& substr) const {
    const char* pos = strstr(this->myString, substr.myString);
    if (pos) {
        return pos - this->myString;
    }
    return -1;
}

// чтение из потока
std::istream& operator>>(std::istream& is, MyString& obj) {
    delete[] obj.myString;
    char buffer[1024];
    is >> buffer;
    size_t size = strlen(buffer) + 1;
    obj.myString = new char[size];
    snprintf(obj.myString, size, "%s", buffer);
    return is;
}

// запись в поток
std::ostream& operator<<(std::ostream& os, const MyString& obj) {
    os << obj.myString;
    return os;
}
