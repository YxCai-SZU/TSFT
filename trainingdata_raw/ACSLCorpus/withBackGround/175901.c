#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        2 <= a && a <= 100 &&
        2 <= b && b <= 100;

    logic integer compute_result(integer a, integer b) =
        a * b - (a + b - 1);

    lemma bounds_lemma:
        \forall integer a, b;
            valid_range(a, b) ==>
            a * b <= 100 * 100 &&
            a * b >= a + b - 1 &&
            b + (a - 1) <= 100 + (100 - 1);
*/

/*@
    requires valid_range(a, b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t temp1;
    uint32_t temp2;
    uint32_t temp3;
    int32_t result;

    //@ assert valid_range(a, b);
    
    //@ assert b + (a - 1) <= 100 + (100 - 1);
    
    //@ assert a * b <= 100 * 100;
    
    //@ assert a * b >= a + b - 1;
    
    temp1 = a * b;
    temp2 = a + b - 1;
    temp3 = temp1 - temp2;
    result = (int32_t)temp3;
    
    //@ assert result == compute_result(a, b);
    return result;
}
