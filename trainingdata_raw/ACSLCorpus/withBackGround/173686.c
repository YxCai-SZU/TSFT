#include <stdint.h>

/*@ predicate is_valid_n(integer n) = 1 <= n && n <= 10000; */

/*@ logic integer mod_1000(integer n) = n % 1000; */

/*@ lemma mod_property: \forall integer n; is_valid_n(n) ==> mod_1000(n) >= 0; */

/*@ requires is_valid_n(n);
    ensures \result == 1000 - (n % 1000);
*/
int32_t func(int32_t n)
{
    uint32_t n_unsigned;
    int32_t result;
    
    //@ assert is_valid_n(n);
    if (n < 0) {
        n_unsigned = (uint32_t)(-n);
    } else {
        n_unsigned = (uint32_t)n;
    }
    result = 1000;
    
    /*@ loop invariant 0 <= n_unsigned <= (uint32_t)n;
        loop invariant n_unsigned % 1000 == (uint32_t)n % 1000;
        loop assigns n_unsigned;
        loop variant n_unsigned;
    */
    while (n_unsigned >= 1000) {
        //@ assert n_unsigned >= 1000;
        n_unsigned -= 1000;
    }
    
    if (n_unsigned != 0) {
        //@ assert n_unsigned == (uint32_t)n % 1000;
        result -= (int32_t)n_unsigned;
    }
    
    //@ assert result == 1000 - (n % 1000);
    return result;
}
