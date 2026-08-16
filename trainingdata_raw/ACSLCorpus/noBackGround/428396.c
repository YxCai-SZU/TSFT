#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 &&
      1 <= (b) <= 100);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result <= a + b + 1;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t max_val;
    uint32_t min_val;
    uint32_t sum;
    uint32_t result;
    uint32_t i;

    //@ assert (1 <= (a) <= 100 &&       1 <= (b) <= 100);
    
    max_val = (a > b) ? a : b;
    min_val = (a < b) ? a : b;
    sum = a + b + 1;
    result = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= sum;
        loop invariant result <= i;
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant max_val >= min_val;
        loop invariant max_val <= 100;
        loop invariant min_val >= 1;
        loop assigns i, result;
    */
    while (i < sum)
    {
        //@ assert max_val <= 100;
        //@ assert min_val >= 1;
        
        if ((max_val + 1) < (i + min_val)) {
            result += 1;
        }
        i += 1;
    }

    if (result == 0) {
        return -1;
    } else {
        return (int32_t)result;
    }
}
