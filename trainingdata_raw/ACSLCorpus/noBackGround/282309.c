#include <limits.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (31415)* (r)) / 10000);
    assigns \nothing;
*/
int func(int r) {
    int pi_approx;
    int scaled_r;
    int circumference;
    int temp;
    int count;
    
    pi_approx = 31415;
    scaled_r = r * 10000;
    circumference = 0;
    temp = 2 * pi_approx * r;
    count = 0;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 31415;
        loop invariant scaled_r == r * 10000;
        loop invariant temp >= 0;
        loop invariant count * 10000 + temp == 2 * pi_approx * r;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 10000) {
        temp -= 10000;
        count += 1;
    }
    
    circumference = count;
    
    //@ assert 2 * 31415 * r == 2 * pi_approx * r;
    
    //@ assert (2 * 31415 * r) / 10000 <= INT_MAX / 10000;
    
    return circumference;
}
