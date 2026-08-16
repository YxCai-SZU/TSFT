#include <stdint.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100000;
    
    logic integer compute_remainder(integer x, integer q) = x + 1000 - 1 - q * 1000;
    
    lemma quotient_bound: \forall integer x, q, r; 
        is_valid_range(x) && 0 <= q && r == compute_remainder(x, q) && r >= 0 ==> q <= 1000;
*/

/*@
    requires is_valid_range(x);
    ensures \result >= 0;
    ensures \result <= 999;
    ensures (x + \result) % 1000 == 0;
*/
int64_t func(int64_t x)
{
    int64_t quotient;
    int64_t remainder;
    int64_t divisor;
    int64_t result;
    
    quotient = 0;
    remainder = x + 1000 - 1;
    divisor = 1000;
    
    /*@
        loop invariant 1 <= x <= 100000;
        loop invariant 0 <= quotient;
        loop invariant remainder == x + 1000 - 1 - quotient * divisor;
        loop invariant remainder >= 0;
        loop invariant quotient <= 1000;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }
    
    result = quotient * 1000 - x;
    //@ assert result >= 0;
    //@ assert result <= 999;
    //@ assert (x + result) % 1000 == 0;
    
    return result;
}
