#include <iostream>
#include <cstdint>
#include <sstream>


#pragma once

using namespace std;

class number {

public:

    char* arr;  
    long long int num_digits; 

    number(long long int num_digits);

    number operator+(const number& other);

    number &operator=(const number& other);

    string to_string();

};

