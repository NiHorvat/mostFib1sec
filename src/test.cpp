#include <iostream>
#include <cstdint>
#include <chrono>
#include<bits/stdc++.h>



#include "number/number.h"



using namespace std;


int main(){


    const long long int n = 5;
    number *a = new number(23);
    *a = 12LL;
    cout << *a << endl;
    number *b = new number(12);
    *b = 13;
    cout << *b << endl;
    number c = *a + *b;

    cout << c ;




    return 0;
}