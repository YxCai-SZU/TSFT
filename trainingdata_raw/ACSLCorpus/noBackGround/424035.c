#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == 2 * 3141592 * r / 1000000;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t pi;
    int64_t two;
    int64_t scale;
    int64_t circumference;
    int64_t temp_r;
    int64_t result;
    
    pi = 3141592;
    two = 2;
    scale = 1000000;
    circumference = 0;
    temp_r = r;
    
    // First loop: compute circumference = r * pi
    //@ assert ((pi) == 3141592);
    //@ assert ((two) == 2);
    //@ assert ((scale) == 1000000);
    //@ assert (1 <= (r) <= 100);
    //@ assert 0 <= temp_r <= r;
    //@ assert circumference == 0;
    
    /*@
        loop invariant 0 <= temp_r <= r;
        loop invariant circumference == (r - temp_r) * pi;
        loop invariant circumference >= 0;
        loop invariant ((pi) == 3141592);
        loop invariant ((two) == 2);
        loop invariant ((scale) == 1000000);
        loop invariant (1 <= (r) <= 100);
        loop assigns circumference, temp_r;
        loop variant temp_r;
    */
    while (temp_r > 0) {
        circumference += pi;
        temp_r -= 1;
    }
    
    circumference *= two;
    
    // Second loop: compute result = circumference / scale
    result = 0;
    
    /*@
        loop invariant circumference >= 0;
        loop invariant 0 <= result;
        loop invariant circumference == (r * pi * two) - (result * scale);
        loop invariant ((pi) == 3141592);
        loop invariant ((two) == 2);
        loop invariant ((scale) == 1000000);
        loop invariant (1 <= (r) <= 100);
        loop assigns result, circumference;
        loop variant circumference;
    */
    while (circumference >= scale) {
        result += 1;
        circumference -= scale;
    }
    
    // Final verification assertions
    //@ assert circumference == (r * pi * two) - (result * scale);
    //@ assert circumference >= 0;
    //@ assert circumference < scale;
    //@ assert result * scale + circumference == 2 * pi * r;
    //@ assert result == 2 * 3141592 * r / 1000000;
    
    return result;
}
