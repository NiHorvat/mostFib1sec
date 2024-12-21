#include <iostream>
#include <cstdint>
#include <chrono>









long long int fibo(int n){

    
    long long int first = 1;
    long long int second = 1;
    long long int temp;

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
        auto fib = fibo(i);
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


}


int main(){

    int num = 1000000;

    std::cout << fibo(1000000);

    return 0;
}