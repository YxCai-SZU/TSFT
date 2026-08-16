#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == 2 * 314159265359 * r / 100000000000;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi = 314159265359;
    int64_t circumference = 0;
    int64_t temp = 2 * pi * r;
    int64_t divisor = 100000000000;
    
    //@ assert temp == (2 * (pi) * (r));
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant temp >= 0;
        loop invariant ((circumference) * (divisor) + (temp) == 2 * (pi) * (r));
        loop assigns temp, circumference;
        loop variant temp;
    */
    while (temp >= divisor) {
        //@ assert temp >= divisor;
        temp -= divisor;
        circumference += 1;
        //@ assert ((circumference) * (divisor) + (temp) == 2 * (pi) * (r));
    }
    
    //@ assert ((circumference) * (divisor) + (temp) == 2 * (pi) * (r));
    //@ assert temp < divisor;
    
    // Final verification of postcondition
    //@ assert circumference == 2 * 314159265359 * r / 100000000000;
    
    return circumference;
}
