#include <stdint.h>

/*@ predicate is_odd(integer n) = n % 2 != 0; */
/*@ predicate is_even(integer n) = n % 2 == 0; */

/*@ lemma lemma_is_odd_or_even: \forall integer n; 1 <= n <= 100 ==> is_odd(n) || is_even(n); */

/*@
    requires 1 <= a <= 100 && 1 <= b <= 100;
    ensures \result == 0 || \result == 1;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    int32_t result;
    
    sum = a + b;
    
    if (sum % 2 == 0) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert result == 0 || result == 1;
    return result;
}
