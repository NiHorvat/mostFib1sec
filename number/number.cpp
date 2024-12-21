#include "number.h"

using namespace std;

class number{
    
    public:
        char *arr ;  
        long long int num_digits;

        number(long long int num_digits){

            arr = new char [num_digits];
            for(int i = 0; i < num_digits; i++){
                arr[i] = '0';
            }


            this->num_digits = num_digits;
        }


        number operator+ (const number & other){

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


        string to_string(){
            string s = "";
            for(int i = num_digits - 1; i >= 0; i--){
                s.push_back(this->arr[i]);
            }
            return s;
        }
};
