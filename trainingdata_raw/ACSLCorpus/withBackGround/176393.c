#include <stdint.h>

/*@
    predicate valid_k(integer k) = 2 <= k && k <= 100;
    
    logic integer half(integer k) = k / 2;
    
    logic integer expected_result(integer k) = half(k) * (k - half(k));
    
    lemma result_bounds: \forall integer k; valid_k(k) ==> 0 <= expected_result(k) <= 2500;
*/

/*@
    requires 2 <= k && k <= 100;
    ensures \result == (k / 2) * (k - k / 2);
    ensures 0 <= \result <= 2500;
*/
int32_t func(int32_t k) {
    int32_t quotient = 0;
    int32_t remainder = k;
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= k / 2;
        loop invariant remainder == k - 2 * quotient;
        loop invariant 2 <= k && k <= 100;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 2) {
        remainder -= 2;
        quotient += 1;
    }
    
    //@ assert 0 <= quotient;
    //@ assert quotient <= k / 2;
    //@ assert remainder == k - 2 * quotient;
    
    //@ assert 0 <= quotient <= 50;
    //@ assert 0 <= k - quotient <= 50;
    
    //@ assert 0 <= quotient * (k - quotient) <= 2500;
    
    return quotient * (k - quotient);
}
