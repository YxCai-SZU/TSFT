#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * 314159265359 * (r) / 100000000000);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi = 314159265359;
    int64_t circumference = 0;
    int64_t temp = 2 * pi * r;
    int64_t divisor = 100000000000;
    
    //@ assert (1 <= (r) <= 100);
    //@ assert pi == 314159265359;
    //@ assert divisor == 100000000000;
    //@ assert temp == 2 * pi * r;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314159265359;
        loop invariant 0 <= circumference;
        loop invariant circumference <= 2 * pi * r / divisor;
        loop invariant temp >= 0;
        loop invariant temp == 2 * pi * r - circumference * divisor;
        loop invariant circumference * divisor + temp == 2 * pi * r;
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        //@ assert temp >= divisor;
        temp -= divisor;
        circumference += 1;
        //@ assert circumference * divisor + temp == 2 * pi * r;
    }
    
    //@ assert temp < divisor;
    //@ assert circumference * divisor + temp == 2 * pi * r;
    //@ assert circumference == (2 * 314159265359 * (r) / 100000000000);
    
    return circumference;
}

int main(void)
{
    return 0;
}
