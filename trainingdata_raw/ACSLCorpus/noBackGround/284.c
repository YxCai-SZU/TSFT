#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (314159265359)* (r)) / (100000000000));
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi = 314159265359;
    int64_t circumference = 0;
    int64_t temp = 2 * pi * r;
    int64_t divisor = 100000000000;
    
    //@ assert 0 <= 2 * pi * r <= 200 * pi;
    //@ assert temp == 2 * pi * r;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant 0 <= temp <= 2 * pi * r;
        loop invariant temp + divisor * circumference == 2 * pi * r;
        loop invariant circumference * divisor <= 2 * pi * r;
        loop assigns temp, circumference;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        circumference += 1;
    }
    
    //@ assert circumference * divisor == (2 * pi * r) - temp;
    
    return circumference;
}

int main()
{
    return 0;
}
