#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        2 <= a && a <= 100 && 2 <= b && b <= 100;

    logic integer compute_result(integer a, integer b) =
        a * b - (a + b - 1);

    lemma multiplication_bound:
        \forall integer a, b; valid_range(a, b) ==> a * b <= 10000;

    lemma subtraction_valid:
        \forall integer a, b; valid_range(a, b) ==> a * b >= a + b - 1;
*/

/*@
    requires valid_range(a, b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t x;
    uint32_t y;
    int32_t result;

    //@ assert valid_range(a, b);
    
    //@ assert a * b <= 10000;
    
    //@ assert a + b - 1 <= 199;
    
    //@ assert a * b >= a + b - 1;

    x = a * b;
    y = a + b - 1;
    result = (int32_t)(x - y);
    
    //@ assert result == compute_result(a, b);
    return result;
}
