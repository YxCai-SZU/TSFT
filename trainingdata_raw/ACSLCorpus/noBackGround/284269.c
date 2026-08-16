#include <stdint.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == (2 * 314159 * r) / 100000;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t circumference;
    int64_t temp;
    int64_t divisor;
    
    pi = 314159;
    circumference = 0;
    temp = 2 * pi * r;
    divisor = 100000;
    
    //@ assert pi == 314159;
    //@ assert 1 <= r <= 100;
    //@ assert temp == 2 * 314159 * r;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314159;
        loop invariant divisor == 100000;
        loop invariant temp >= 0;
        loop invariant circumference * divisor + temp == 2 * pi * r;
        loop assigns temp, circumference;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp = temp - divisor;
        circumference = circumference + 1;
        
        //@ assert circumference * divisor + temp == 2 * pi * r;
    }
    
    return circumference;
}

int main(void)
{
    return 0;
}
