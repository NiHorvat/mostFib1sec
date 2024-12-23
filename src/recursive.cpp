#include <iostream>
#include <cstdint>
#include <chrono>


long long int fibo(int n){

    if(n <= 2) return 1;
    
    return fibo(n - 1) + fibo(n - 2);
}

void test(int n){

    for(int i = 1; i < n; i++){
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


    test(100);

    return 0;
}