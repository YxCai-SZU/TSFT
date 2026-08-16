#include <stdint.h>

/*@
    predicate is_valid_remainder(integer r) = 0 <= r && r < 11;
    predicate is_valid_quotient(integer q, integer x) = 0 <= q && q <= x / 11;
    predicate division_invariant(integer q, integer r, integer x) = 
        is_valid_quotient(q, x) && is_valid_remainder(r) && r == x - q * 11;
    
    lemma quotient_bound: \forall integer x, q; 
        is_valid_quotient(q, x) ==> q * 2 <= x / 11 * 2;
    lemma remainder_bound: \forall integer r; 
        is_valid_remainder(r) ==> (r > 6 ? 2 : 1) <= 2;
*/

/*@
    requires x <= 100000000000000000;
    ensures \result <= x / 11 * 2 + 2;
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t quotient;
    uint64_t remainder;
    uint64_t result;
    
    quotient = 0;
    remainder = x;
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= x / 11;
        loop invariant remainder == x - quotient * 11;
        loop invariant 0 <= remainder;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 11)
    {
        //@ assert remainder == x - quotient * 11;
        quotient = quotient + 1;
        remainder = remainder - 11;
        //@ assert remainder == x - quotient * 11;
    }
    
    //@ assert is_valid_remainder(remainder);
    //@ assert is_valid_quotient(quotient, x);
    
    result = quotient * 2;
    
    if (remainder > 6)
    {
        //@ assert result + 2 <= x / 11 * 2 + 2;
        return result + 2;
    }
    else
    {
        //@ assert result + 1 <= x / 11 * 2 + 2;
        return result + 1;
    }
}
