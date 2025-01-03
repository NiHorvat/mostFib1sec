#include <iostream>
#include <cstdint>
#include <sstream>
#include <string>
#include <bits/stdc++.h>



using namespace std;

class number {
    

public:

    char* arr;  
    long long int num_digits; 

    number();

    number(long long int num_digits);

    number operator+(const number& other);

    number &operator=(const number& other);

    number &operator=(const long long int &other);

    string to_string();

    friend ostream &operator<<(ostream &out,number &n);    

};

    
