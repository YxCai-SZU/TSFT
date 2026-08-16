#include <stdint.h>

/*@
    requires (1 <= (n) <= 10000);
    ensures \result >= 0;
    ensures \result < 1000;
    ensures \result == ((1000 - (n) % 1000) % 1000);
*/
int64_t func(int64_t n)
{
    int64_t sum;
    int64_t result;
    
    sum = 1000;
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant sum >= 1000;
        loop invariant sum < 1000 + n;
        loop invariant sum % 1000 == 0;
        loop invariant sum - n < 1000;
        loop assigns sum;
        loop variant n - sum / 1000;
    */
    while (sum < n)
    {
        //@ assert sum % 1000 == 0;
        sum += 1000;
    }
    
    result = sum - n;
    
    //@ assert result >= 0;
    //@ assert result < 1000;
    //@ assert result == ((1000 - (n) % 1000) % 1000);
    
    return result;
}
