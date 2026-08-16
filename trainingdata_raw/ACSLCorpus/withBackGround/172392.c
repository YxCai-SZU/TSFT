#include <stdbool.h>

/*@
    predicate is_valid_range(integer a, integer b, integer c, integer d, integer e) =
        0 <= a && a < b && b < c && c < d && d < e && e <= 123;
    
    predicate is_valid_k(integer k) =
        0 <= k && k <= 123;
    
    logic integer condition_holds(integer a, integer b, integer c, integer d, integer e, integer k) =
        (b - a <= k ? 1 : 0) + (c - a <= k ? 1 : 0) + (d - a <= k ? 1 : 0) + (e - a <= k ? 1 : 0) +
        (c - b <= k ? 1 : 0) + (d - b <= k ? 1 : 0) + (e - b <= k ? 1 : 0) +
        (d - c <= k ? 1 : 0) + (e - c <= k ? 1 : 0) + (e - d <= k ? 1 : 0);
    
    lemma difference_bounds:
        \forall integer a, b, c, d, e, k;
        is_valid_range(a, b, c, d, e) && is_valid_k(k) ==>
        0 <= b - a && b - a <= 123;
*/

/*@
    requires is_valid_range(a, b, c, d, e);
    requires is_valid_k(k);
    ensures \result == (condition_holds(a, b, c, d, e, k) > 0);
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    bool result = false;
    
    //@ assert 0 <= b - a && b - a <= 123;
    
    if (b - a <= k) {
        result = true;
    } else if (c - a <= k) {
        result = true;
    } else if (d - a <= k) {
        result = true;
    } else if (e - a <= k) {
        result = true;
    } else if (c - b <= k) {
        result = true;
    } else if (d - b <= k) {
        result = true;
    } else if (e - b <= k) {
        result = true;
    } else if (d - c <= k) {
        result = true;
    } else if (e - c <= k) {
        result = true;
    } else if (e - d <= k) {
        result = true;
    }
    
    //@ assert result == (condition_holds(a, b, c, d, e, k) > 0);
    
    return result;
}
