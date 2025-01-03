#include "number.h"


number::number(long long int num_digits){

    arr = new char [num_digits];
    for(int i = 0; i < num_digits; i++){
        arr[i] = '0';
    }


    this->num_digits = num_digits;
}


number number::operator+(const number & other){

    number output(num_digits);

    char carry = 0;
    char res;
    for(int i = 0; i < num_digits; i++){

        res = arr[i] + other.arr[i] + carry - '0' - '0';
        carry = res / 10;
        output.arr[i] = res % 10 + '0';
    }

    if(carry != 0) throw overflow_error("overflow buraz");
    return output;
};

number &number::operator=(const number &other){
    
    if (this == &other) {
        return *this; 
    }
    this->num_digits = other.num_digits;

    delete[] this->arr;
    this->arr = new char[this->num_digits];

    for(long long int i = 0; i < this->num_digits; i++){
        this->arr[i] = other.arr[i];
    }

    return *this;
}

string number::to_string(){
    string s = "";
    for(int i = num_digits - 1; i >= 0; i--){
        s.push_back(this->arr[i]);
    }
    return s;
}




