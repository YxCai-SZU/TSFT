#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        2 <= a && a <= 100 &&
        2 <= b && b <= 100;

    logic integer compute_result(integer a, integer b) =
        a * b - (a + b - 1);

    lemma product_bound: \forall integer a, b;
        valid_range(a, b) ==> a * b <= 100 * 100;

    lemma subtraction_valid: \forall integer a, b;
        valid_range(a, b) ==> a * b >= a + b - 1;
*/

/*@
    requires valid_range(a, b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t result;
    uint32_t subtract;
    uint32_t ans;

    //@ assert valid_range(a, b);
    
    //@ assert a * b <= 100 * 100;
    result = a * b;
    
    subtract = a + b - 1;
    
    //@ assert a * b >= a + b - 1;
    ans = result - subtract;
    
    return (int32_t)ans;
}
