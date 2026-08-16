/*@
    predicate valid_params(integer A, integer P) =
        0 <= A && A <= 100 &&
        0 <= P && P <= 100;
    
    logic integer compute_upper_bound(integer A, integer P) = A * 3 + P;
    
    lemma quotient_nonnegative:
        \forall integer A, P, ret, quotient, temp, divisor;
        valid_params(A, P) &&
        ret == compute_upper_bound(A, P) &&
        divisor == 2 &&
        quotient >= 0 &&
        temp >= 0 &&
        quotient * 2 + temp == ret ==>
        quotient >= 0;
*/

#include <stdint.h>

/*@
    requires valid_params(A, P);
    ensures \result >= 0 && \result <= compute_upper_bound(A, P);
*/
int32_t func(int32_t A, int32_t P)
{
    int32_t ret;
    int32_t quotient;
    int32_t temp;
    int32_t divisor;
    
    ret = A * 3 + P;
    quotient = 0;
    temp = ret;
    divisor = 2;
    
    //@ assert ret == compute_upper_bound(A, P);
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= compute_upper_bound(A, P) / 2;
        loop invariant 0 <= temp;
        loop invariant temp <= compute_upper_bound(A, P);
        loop invariant divisor == 2;
        loop invariant ret == compute_upper_bound(A, P);
        loop invariant quotient * 2 + temp == ret;
        loop assigns quotient, temp;
    */
    while (temp >= divisor) {
        //@ assert temp >= 2;
        temp -= divisor;
        quotient += 1;
        //@ assert quotient * 2 + temp == ret;
    }
    
    //@ assert quotient >= 0;
    //@ assert quotient <= compute_upper_bound(A, P);
    return quotient;
}
