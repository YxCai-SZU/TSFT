#include <stdbool.h>

/*@
    predicate nonnegative(integer a, integer b, integer c, integer k) =
        a >= 0 && b >= 0 && c >= 0 && k >= 1 && a + b + c >= k;
*/

/*@
    logic integer func_spec(integer a, integer b, integer c, integer k) =
        k <= a ? k : (k <= a + c ? a - (k - a) : a - c);
*/

/*@
    lemma result_range:
        \forall integer a, b, c, k;
        nonnegative(a, b, c, k) ==>
        func_spec(a, b, c, k) >= -c && func_spec(a, b, c, k) <= a;
*/

/*@
    requires nonnegative(a, b, c, k);
    ensures \result >= -c && \result <= a;
    ensures \result == func_spec(a, b, c, k);
*/
int func(int a, int b, int c, int k)
{
    int result = 0;
    int k_remaining = k;
    
    // Use all positive numbers first
    if (a <= k_remaining) {
        result += a;
        k_remaining -= a;
    } else {
        result += k_remaining;
        k_remaining = 0;
    }
    
    //@ assert result >= -c;
    
    // Use all negative numbers
    if (k_remaining > 0) {
        if (k_remaining > c) {
            result -= c;
            k_remaining -= c;
        } else {
            result -= k_remaining;
            k_remaining = 0;
        }
    }
    
    //@ assert result <= a;
    
    return result;
}
