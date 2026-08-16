#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * 31415 * (r) / 10000);
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi;
    int64_t result;
    int64_t temp;
    int64_t count;
    int64_t divisor;
    
    pi = 31415;
    result = 0;
    temp = 2 * pi * r;
    count = 0;
    divisor = 10000;
    
    //@ assert ((pi) == 31415);
    //@ assert ((divisor) == 10000);
    //@ assert ((temp) >= 0);
    //@ assert ((count) >= 0);
    //@ assert ((temp) == 2 * (pi) * (r) - (count) * (divisor));
    
    /*@
        loop invariant (1 <= (r) <= 100);
        loop invariant ((pi) == 31415);
        loop invariant ((divisor) == 10000);
        loop invariant ((temp) >= 0);
        loop invariant ((count) >= 0);
        loop invariant ((temp) == 2 * (pi) * (r) - (count) * (divisor));
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= divisor) {
        temp -= divisor;
        count += 1;
        //@ assert ((temp) == 2 * (pi) * (r) - (count) * (divisor));
    }
    
    //@ assert temp < divisor;
    //@ assert 2 * pi * r == temp + divisor * count;
    
    result = count;
    return result;
}
