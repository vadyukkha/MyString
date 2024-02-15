// Copyright 2024 by Contributors
#include "../include/MyString.h"

int main() {
    MyString my_string_to_move("move");  // const char*
    MyString my_string_abc("abc");  // const char*
    std::string string_hello = "Hello,";

    MyString my_string_hello(string_hello);  // std::string
    std::cout << my_string_hello << std::endl;  // Hello,

    MyString my_string_world("world!");
    MyString my_string_moved(std::move(my_string_to_move));  // move-constructor
    std::cout << my_string_moved << std::endl;  // move

    MyString my_string_copy(my_string_abc);  // copy-constructor
    std::cout << my_string_copy << std::endl;  // abc

    MyString my_string_hello_world;
    my_string_hello_world = my_string_hello + my_string_world;

    std::cout << my_string_hello_world << std::endl;  // Hello,world!
    std::cout << my_string_hello_world.length() << std::endl;  // 12
    std::cout << my_string_hello_world((MyString)"ll") << std::endl;  // 2
    std::cout << my_string_hello_world((MyString)"mama") << std::endl;  // -1

    MyString my_string_abbxaxca("abbxaxca");
    MyString my_string_abcabcabc = my_string_abc * 3;
    MyString my_string_xx = my_string_abbxaxca - my_string_abc;

    std::cout << "abbxaxca - abc: " << my_string_xx << std::endl;  // xx
    std::cout << "abc * 3: "
        << my_string_abcabcabc << std::endl;  // abcabcabc

    std::cout << "hello == world: "
        << (my_string_hello == my_string_world) << std::endl;  // false
    std::cout << "hello != world: "
        << (my_string_hello != my_string_world) << std::endl;  // true
    std::cout << "hello > world: "
        << (my_string_hello > my_string_world) << std::endl;   // false
    std::cout << "hello < world: "
        << (my_string_hello < my_string_world) << std::endl;   // true
    std::cout << "hello >= world: "
        << (my_string_hello >= my_string_world) << std::endl;  // false
    std::cout << "hello <= world: "
        << (my_string_hello <= my_string_world) << std::endl;  // true

    std::cout << "!abc: " << !my_string_abc << std::endl;  // ABC
    std::cout << "abc[0]: " << my_string_abc[0] << std::endl;  // a

    MyString my_string_input;
    std::cout << "Enter a string: ";
    std::cin >> my_string_input;
    std::cout << "output: " << my_string_input << std::endl;

    MyString my_string_blablabla;
    my_string_blablabla = (MyString)"blablabla";
    std::cout << my_string_blablabla << std::endl;  // blablabla

    std::cout << my_string_abc.get() << std::endl;  // abc

    MyString my_string_meow = (MyString)"Meow";
    MyString my_string_foo = (MyString)"Foo";
    MyString my_string_woops = (MyString)"Woops";
    my_string_meow = my_string_foo + my_string_woops + (MyString)"Baz";

    std::cout << my_string_meow  << std::endl;  // FooWoopsBaz
    return EXIT_SUCCESS;
}
