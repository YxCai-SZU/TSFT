#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (314159)* (r)) / (100000));
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t circumference = 0;
    int64_t temp = 0;
    int64_t divisor = 0;
    int64_t pi_approx = 0;
    
    pi_approx = 314159;
    divisor = 100000;
    temp = 2 * pi_approx * r;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant (314159)== 314159;
        loop invariant divisor == 100000;
        loop invariant temp >= 0;
        loop invariant circumference * divisor + temp == 2 * (314159)* r;
        loop assigns temp, circumference;
    */
    while (temp >= divisor) {
        //@ assert temp >= divisor;
        temp -= divisor;
        circumference += 1;
    }
    
    //@ assert temp < divisor;
    return circumference;
}
