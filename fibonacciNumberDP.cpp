//
//  fibonacciNumberDP.cpp
//  TestingC++
//
//  Created by Ankit Baid on 03/02/18.
//  Copyright © 2018 Ankit Baid. All rights reserved.
//

#include <iostream>
#define NIL -1
#define MAX 100

using namespace std;

int lookup[MAX];

int fib(int n){
    if(lookup[n] == NIL){
        if(n <= 1)
            lookup[n] = n;
        else
            lookup[n] = fib(n-1) + fib(n-2);
    }
    return lookup[n];
}

int main(){
    
    for(int i=0; i<MAX; i++){
        lookup[i] = NIL;
    }
    
    cout << fib(6) << endl;
    
    return 0;
}

