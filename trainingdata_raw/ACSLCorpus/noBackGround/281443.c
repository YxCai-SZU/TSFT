#include <stdint.h>

/*@
    requires (1 <= (a) <= 100);
    ensures \result == ((2 * 314159 * ((a))) / 100000);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    int64_t pi;
    int64_t result;
    int64_t quotient;
    int64_t divisor;
    
    pi = 314159;
    result = 2 * pi * a;
    quotient = 0;
    divisor = 100000;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant pi == 314159;
        loop invariant divisor == 100000;
        loop invariant result >= 0;
        loop invariant result <= 2 * pi * a;
        loop invariant quotient * divisor + result == 2 * pi * a;
        loop assigns result, quotient;
        loop variant result;
    */
    while (result >= divisor)
    {
        result -= divisor;
        quotient += 1;
    }
    
    //@ assert quotient * divisor + result == 2 * pi * a;
    
    return quotient;
}

int main(void)
{
    return 0;
}
