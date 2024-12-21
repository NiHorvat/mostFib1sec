#include <iostream>
#include <cstdint>
#include <sstream>

class number {

public:

    char* arr;  
    long long int num_digits; 

    number(long long int num_digits);

    number operator+(const number& other);

    std::string to_string();

};
