#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (314159)* (r)) / (100000));
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi_approx;
    int64_t scale;
    int64_t circumference;
    int64_t temp;
    
    pi_approx = 314159;
    scale = 100000;
    circumference = 0;
    temp = 2 * pi_approx * r;
    
    //@ assert pi_approx == (314159);
    //@ assert scale == (100000);
    //@ assert temp == 2 * (314159)* r;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 314159;
        loop invariant scale == 100000;
        loop invariant temp >= 0;
        loop invariant circumference * scale + temp == 2 * pi_approx * r;
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= scale) {
        circumference += 1;
        temp -= scale;
    }
    
    //@ assert temp >= 0 && temp < scale;
    //@ assert circumference * scale + temp == 2 * (314159)* r;
    
    // Critical verification property for postcondition
    //@ assert circumference == ((2 * (314159)* (r)) / (100000));
    
    return circumference;
}
