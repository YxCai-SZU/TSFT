#include <stdint.h>

/*@
    predicate is_valid_range(integer a) = 1 <= a <= 100000;
    
    logic integer compute_result(integer a) = (a + 1) / 2;
    
    lemma result_property: \forall integer a; is_valid_range(a) ==> compute_result(a) >= 0;
*/

/*@
    requires is_valid_range(a);
    ensures \result == compute_result(a);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    int64_t result;
    int64_t quotient;
    int64_t abs_result;
    
    result = a + 2 - 1;
    quotient = 0;
    
    //@ assert result == a + 1;
    
    if (result < 0) {
        abs_result = -result;
    } else {
        abs_result = result;
    }
    
    //@ assert abs_result >= 0;
    
    /*@
        loop invariant 1 <= a <= 100000;
        loop invariant abs_result >= 0;
        loop invariant result == a + 1;
        loop invariant quotient >= 0;
        loop invariant abs_result == result - 2 * quotient;
        loop assigns abs_result, quotient;
        loop variant abs_result;
    */
    while (abs_result >= 2)
    {
        //@ assert abs_result >= 2;
        abs_result -= 2;
        quotient += 1;
        //@ assert quotient >= 0;
    }
    
    if (result < 0) {
        quotient = -quotient;
    }
    
    //@ assert quotient == compute_result(a);
    return quotient;
}
