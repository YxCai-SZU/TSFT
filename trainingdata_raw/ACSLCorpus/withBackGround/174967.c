#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 179;
    
    logic integer expected_result(integer x) = (x * 8) / 100;
    
    lemma division_property:
        \forall integer x, q, r;
            is_valid_range(x) ==>
            x * 8 == q * 100 + r ==>
            0 <= r < 100 ==>
            q == expected_result(x);
*/

/*@
    requires is_valid_range(x);
    ensures \result == expected_result(x);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    int quotient = 0;
    int remainder;
    
    result = x * 8;
    remainder = result;
    
    /*@
        loop invariant 1 <= x <= 179;
        loop invariant result == x * 8;
        loop invariant quotient >= 0;
        loop invariant remainder >= 0;
        loop invariant remainder == result - quotient * 100;
        loop invariant quotient == expected_result(x) - (remainder / 100);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 100)
    {
        //@ assert remainder >= 100;
        quotient += 1;
        //@ assert quotient * 100 <= result;
        remainder -= 100;
        //@ assert remainder == result - quotient * 100;
    }
    
    //@ assert remainder < 100;
    //@ assert quotient * 100 <= result < (quotient + 1) * 100;
    //@ assert quotient == expected_result(x);
    
    return quotient;
}
