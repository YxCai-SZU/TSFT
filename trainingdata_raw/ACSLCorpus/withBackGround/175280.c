#include <stdbool.h>

/*@
    predicate is_valid_range(integer a, integer b, integer c, integer d, integer e) =
        0 <= a && a < b && b < c && c < d && d < e && e <= 123;

    predicate k_in_range(integer k) = 0 <= k && k <= 123;

    logic integer condition_holds(integer a, integer b, integer c, integer d, integer e, integer k) =
        (k >= (e - a) || k >= (c - b) || k >= (b - a) || k >= (d - c) || k >= (e - d) ||
        k >= (c - a) || k >= (e - b) || k >= (d - b) || k >= (d - a) || k >= (b - e) ||
        k >= (a - c) || k >= (b - d) || k >= (a - e) || k >= (d - e) || k >= (c - e) ||
        k >= (e - c) || k >= (b - c) || k >= (c - b) || k >= (a - b) || k >= (b - a)) ? 1 : 0;

    lemma all_conditions_false:
        \forall integer a, b, c, d, e, k;
        is_valid_range(a, b, c, d, e) && k_in_range(k) &&
        condition_holds(a, b, c, d, e, k) == 0 ==>
        k < (e - a) && k < (c - b) && k < (b - a) && k < (d - c) && k < (e - d) &&
        k < (c - a) && k < (e - b) && k < (d - b) && k < (d - a) && k < (b - e) &&
        k < (a - c) && k < (b - d) && k < (a - e) && k < (d - e) && k < (c - e) &&
        k < (e - c) && k < (b - c) && k < (c - b) && k < (a - b) && k < (b - a);
*/

/*@
    requires is_valid_range(a, b, c, d, e);
    requires k_in_range(k);
    ensures \result == (condition_holds(a, b, c, d, e, k) == 1);
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    bool result;
    //@ assert is_valid_range(a, b, c, d, e);
    
    if (k >= (e - a) || k >= (c - b) || k >= (b - a) || k >= (d - c) || k >= (e - d) ||
        k >= (c - a) || k >= (e - b) || k >= (d - b) || k >= (d - a) || k >= (b - e) ||
        k >= (a - c) || k >= (b - d) || k >= (a - e) || k >= (d - e) || k >= (c - e) ||
        k >= (e - c) || k >= (b - c) || k >= (c - b) || k >= (a - b) || k >= (b - a)) {
        result = true;
        //@ assert condition_holds(a, b, c, d, e, k) == 1;
        return result;
    }
    
    result = false;
    //@ assert condition_holds(a, b, c, d, e, k) == 0;
    return result;
}
