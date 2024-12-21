#include <iostream>
#include <cstdint>
#include <chrono>


#include "number/number.h"

#define NUM_DIG 100


number fibo(int n){

    
    number first = number(NUM_DIG);
    first.arr[0] = '1';
    number second = number(NUM_DIG);
    second.arr[0] = '1';
    number temp = number(NUM_DIG);

    for(int i = 0; i < n; i++){
        temp = second;
        second = second + first;
        first = temp;
    }
    return second;
}







void test(int n){

    for(int i = 1; i < n; i *= 10){
        auto start = std::chrono::high_resolution_clock::now();
        auto fib = fibo((long long) i);
        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        if(duration <= std::chrono::milliseconds(1000)){
            std::cout <<"for n = " << i << " fib number = "<< fib.to_string() << "\n";
            std::cout << "time = " << duration.count() << "\n";
            std::cout << std::endl;
        }
        else{
            break;
        }


    }


}


int main(){

    test(1000000);

    return 0;
}