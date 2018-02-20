#include <iostream>
// Start counting at 0: nth_prime(0) == 2
// (no, 1 is not a prime)
bool is_prime(unsigned[], unsigned, unsigned);
bool is_divisible(unsigned, unsigned);
unsigned sqr(unsigned x){
    return x * x;
}
unsigned nth_prime(unsigned n)
{
    // TODO
    unsigned primes [n+1];
    primes[0] = 2;
    unsigned i = 0;
    while(i < n){
        unsigned g = primes[i++]+1;
        while(!is_prime(primes, g, i)){
            ++g;
        }
        primes[i] = g;
    }
    return primes[n];
}

bool is_prime(unsigned primes[], unsigned g, unsigned n){
    if(g == 2){
        return true;
    }
    int j = 0;
    while(j < n){
        if(is_divisible(g,primes[j++])){
            return false;
        }
    }
    return true;
}

bool is_divisible(unsigned a, unsigned b){
    return b!=0 ? a%b == 0 : false;
}