#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * r * 314159) / 100000;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi;
    int64_t result;
    int64_t temp;
    int64_t count;
    int64_t divisor;
    
    pi = 314159;
    result = 0;
    temp = 2 * r * pi;
    count = 0;
    divisor = 100000;
    
    //@ assert ((pi) == 314159);
    //@ assert ((divisor) == 100000);
    //@ assert temp == (2 * (r) * (pi));
    
    /*@
        loop invariant (1 <= (r) <= 100);
        loop invariant ((pi) == 314159);
        loop invariant ((divisor) == 100000);
        loop invariant 0 <= temp <= 2 * 100 * 314159;
        loop invariant 0 <= count <= (2 * 100 * 314159) / 100000;
        loop invariant temp == 2 * r * pi - count * divisor;
        loop assigns temp, count;
    */
    while (temp >= divisor) {
        //@ assert temp >= divisor;
        temp -= divisor;
        count += 1;
        //@ assert temp == 2 * r * pi - count * divisor;
    }
    
    result = count;
    //@ assert result == ((2 * (r) * (pi)) / (divisor));
    return result;
}
