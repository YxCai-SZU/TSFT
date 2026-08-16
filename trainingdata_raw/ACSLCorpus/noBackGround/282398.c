#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * 314159 * (r)) / 100000);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t scale;
    int64_t circumference;
    int64_t temp;
    
    pi = 314159;
    scale = 100000;
    circumference = 0;
    temp = 2 * pi * r;
    
    /*@
        loop invariant (1 <= (r) <= 100);
        loop invariant ((pi) == 314159);
        loop invariant ((scale) == 100000);
        loop invariant 0 <= temp;
        loop invariant temp == 2 * pi * r - circumference * scale;
        loop invariant circumference >= 0;
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= scale)
    {
        //@ assert temp >= scale;
        circumference = circumference + 1;
        temp = temp - scale;
    }
    
    //@ assert circumference == ((2 * 314159 * (r)) / 100000);
    return circumference;
}
