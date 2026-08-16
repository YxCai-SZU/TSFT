#include <stdint.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == ((2 * (3142)* (r)) / (1000));
    assigns \nothing;
*/
int64_t func(int64_t r) {
    int64_t pi;
    int64_t scale;
    int64_t scaled_r;
    int64_t circumference;
    int64_t temp;
    int64_t divisor;
    
    pi = 3142;
    scale = 1000;
    scaled_r = r * scale;
    circumference = 0;
    temp = 2 * pi * r;
    divisor = scale;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 3142;
        loop invariant scale == 1000;
        loop invariant scaled_r == r * scale;
        loop invariant divisor == scale;
        loop invariant circumference * scale + temp == 2 * pi * r;
        loop invariant temp >= 0;
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= divisor) {
        //@ assert circumference * scale + temp == 2 * pi * r;
        temp -= divisor;
        circumference += 1;
        //@ assert circumference * scale + temp == 2 * pi * r;
    }
    
    //@ assert circumference == ((2 * (3142)* (r)) / (1000));
    return circumference;
}
