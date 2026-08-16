#include <stdint.h>

/*@
    predicate is_valid_range(integer r) = 1 <= r <= 100;
    
    logic integer scaled_pi = 314159;
    logic integer two_val = 2;
    logic integer scale_val = 100000;
    
    logic integer expected_result(integer r) = 
        (two_val * scaled_pi * r) / scale_val;
    
    lemma overflow_bound: 
        \forall integer r; is_valid_range(r) ==> 
            two_val * scaled_pi * r <= 2 * 314159 * 100;
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == (2 * 314159 * r) / 100000;
    assigns \nothing;
*/
int64_t func(int64_t r) {
    int64_t pi = 314159;
    int64_t two = 2;
    int64_t scale_factor = 100000;
    
    //@ assert two == 2;
    //@ assert pi == 314159;
    //@ assert scale_factor == 100000;
    
    //@ assert two * pi * r <= 2 * 314159 * 100;
    
    int64_t numerator = two * pi * r;
    int64_t denominator = scale_factor;
    
    int64_t quotient = 0;
    int64_t remainder = numerator;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314159;
        loop invariant two == 2;
        loop invariant scale_factor == 100000;
        loop invariant numerator == two * pi * r;
        loop invariant denominator == scale_factor;
        loop invariant quotient * denominator + remainder == numerator;
        loop invariant quotient >= 0;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= denominator) {
        quotient += 1;
        remainder -= denominator;
    }
    
    //@ assert quotient == expected_result(r);
    return quotient;
}

int main() {
    return 0;
}
