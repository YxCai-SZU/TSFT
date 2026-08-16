#include <stdint.h>

/*@
    predicate is_nonnegative(integer x) = x >= 0;
    predicate is_in_range(integer x, integer low, integer high) = low <= x <= high;
*/

/*@
    logic integer compute_diff(integer a, integer b) =
        a >= 2 * b ? a - 2 * b : 0;
*/

/*@
    lemma diff_nonnegative:
        \forall integer a, b;
            a >= 0 && b >= 0 ==>
            compute_diff(a, b) >= 0;
*/

/*@
    lemma diff_bound:
        \forall integer a, b;
            a >= 0 && b >= 0 ==>
            compute_diff(a, b) <= a;
*/

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    ensures \result >= 0;
    ensures \result <= a + 2 * b;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b)
{
    int32_t diff;
    int32_t sum;

    //@ assert is_in_range(a, 0, 100);
    //@ assert is_in_range(b, 0, 100);
    
    diff = (a >= 2 * b) ? (a - 2 * b) : 0;
    
    //@ assert is_nonnegative(diff);
    //@ assert diff <= a;
    
    //@ assert a - diff <= a;
    sum = a - diff;
    
    //@ assert is_nonnegative(sum);
    //@ assert sum <= a;
    
    return sum;
}
