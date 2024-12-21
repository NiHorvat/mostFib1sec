#include <iostream>
#include <cstdint>
#include <chrono>
#include <sstream>


using namespace std;

class number{
    
    /*
    
        moj proizvoljno veliki broj klasa
    
    */


    public:
        bool *arr ;  
        int num_bits;

        number(int num_bits){
            arr = (bool*)malloc(num_bits * sizeof(bool));
            this->num_bits = num_bits;
        }


        number operator+ (const number & other){

            bool carry = false;
            number output = number(num_bits);

            /*
            
                ako mi je prvi bit = 1 bacam error da je overflow
            
            */
            for(int i = 0; i < num_bits - 1; i++){
                if(this->arr[i] && other.arr[i]){
                    if(carry) output.arr[i] = true; // 1 + 1 + 1 = 1; c = 1
                    else{
                        output.arr[i] = false; // 1 + 1 + 0 = 0; c = 1
                        carry = true;
                    }
                }
                else if(this->arr[i] || other.arr[i]){
                    if(carry) output.arr[i] = false;  //1 + 0 + 1 = 0; c = 1
                    else{
                        //nema carry 1 + 0 + 0 = 0; c = 0
                        output.arr[i] = false;
                    }
                }
                else{
                    output.arr[i] = carry; // 0 + 0 + c = c; c = 0
                    carry = false;
                } 
            }
                
                if(carry) throw overflow_error("\n\n!!!!Crazy overflow!!!!\n\n");
            }

};


int main(){


    return 0;
}