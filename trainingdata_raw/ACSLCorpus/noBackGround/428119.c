#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == 800 * (int64_t)n - (int64_t)(n / 15) * 200;
*/
int64_t func(uint64_t n)
{
    // Variable declarations
    uint64_t x;
    uint64_t quotient = 0;
    uint64_t temp = n;
    int64_t ans;
    
    //@ assert (1 <= (n) && (n) <= 100);
    
    x = 800 * n;
    
    /*@
        loop invariant 0 <= quotient <= n / 15;
        loop invariant temp == n - quotient * 15;
        loop assigns quotient, temp;
        loop variant temp;
    */
    while (temp >= 15) {
        //@ assert temp >= 15;
        quotient += 1;
        temp -= 15;
    }
    
    //@ assert temp == n - quotient * 15;
    //@ assert temp < 15;
    //@ assert quotient == n / 15;
    
    ans = (int64_t)x - (int64_t)(quotient * 200);
    
    //@ assert ans == 800 * (int64_t)n - (int64_t)(n / 15) * 200;
    
    return ans;
}
