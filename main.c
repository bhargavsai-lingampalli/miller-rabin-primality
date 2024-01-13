#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

unsigned long long int pow_mod(unsigned long long int base, unsigned long long int exp, unsigned long long int mod)
{
    unsigned long long int result=1;
    while (exp)
    {
        if (exp % 2 == 1)
            result = result * base % mod;
        exp >>= 1;
        base = base * base % mod;
    }
    
    return result;
}

bool is_prime(unsigned long long int num)
{
    unsigned long long int k = 0, a, b, i, m=num-1;
    if (num % 2 == 0 || num == 3)
        return (num == 2 || num == 3)? true: false;
    while (m % 2 == 0)
    {
        k += 1;
        m = m >> 1;
    }
    
    srand(time(NULL));
    a = 2 + (rand() % (num-3));
    b = pow_mod(a, m, num);
    if (b == 1 || b == (num -1)) return true;
    
    for(i=0; i<k; i++)
    {
        b = pow_mod(b, 2, num);
        if (b == 1) return false;
        if (b == (num - 1)) return true;
    }
    
    return false;
    
}


int main()
{
    puts(is_prime(3)? "true": "false");
    return 0;
}
