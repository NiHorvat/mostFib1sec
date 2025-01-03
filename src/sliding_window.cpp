#include <iostream>
#include <cstdint>
#include <chrono>
#include<bits/stdc++.h>



#include "number/number.h"



long long numberOfDigits(long long n)
{
    if (n == 1)
        return 1;
 
    // using phi = 1.6180339887498948
    long double d = (n * log10(1.6180339887498948)) -
                    ((log10(5)) / 2);
 
    return ceil(d);
}



number fibo(long long int n){

    long long int num_digits = numberOfDigits(n);
    num_digits += 10;

    number first = number(num_digits);
    first.arr[0] = '1';
    number second = number(num_digits);
    second.arr[0] = '1';
    number temp =  number(num_digits);

    for(int i = 0; i < n; i++){
        temp = second;
        second = second + first;
        first = temp;
    }

    return second;
}


void test(long long int n){

    std::cout << "starting test..." << std::endl;

    for(long long int i = 10000; i < n; i +=1000){
    try{
        auto start = std::chrono::high_resolution_clock::now();
        number fib = fibo(i);
        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        

        if(duration <= std::chrono::milliseconds(1000)){
            std::cout <<"for n = " << i << " fib number = "<< fib << "\n";
            std::cout << "time = " << duration.count() << "\n";
            std::cout << std::endl;

        }
        else{
            break;
            }
        }
        catch(overflow_error e){
            std::cout << e.what() << std::endl;
        }
    }
}


int main(){

    test(100000);

    return 0;
}