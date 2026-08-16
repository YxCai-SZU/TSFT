#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (3141592)* (r)) / 1000000);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi = 3141592;
    int64_t circumference = 0;
    int64_t temp = 2 * pi * r;
    int64_t divisor = 1000000;
    
    //@ assert pi == (3141592);
    //@ assert divisor == 1000000;
    //@ assert temp == 2 * (3141592)* r;
    
    /*@
        loop invariant (1 <= (r) <= 100);
        loop invariant pi == (3141592);
        loop invariant divisor == 1000000;
        loop invariant 0 <= temp <= 2 * (3141592)* r;
        loop invariant circumference * 1000000 + temp == 2 * (3141592)* r;
        loop invariant circumference >= 0;
        loop assigns temp, circumference;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        //@ assert temp >= 1000000;
        temp -= divisor;
        circumference += 1;
        //@ assert circumference * 1000000 + temp == 2 * (3141592)* r;
    }
    
    //@ assert temp < 1000000;
    //@ assert circumference * 1000000 + temp == 2 * (3141592)* r;
    //@ assert circumference == ((2 * (3141592)* (r)) / 1000000);
    
    return circumference;
}
