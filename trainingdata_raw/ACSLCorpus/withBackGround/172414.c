#include <stdbool.h>

/*@ predicate is_ordered(integer a, integer b, integer c, integer d, integer e) =
       a < b && b < c && c < d && d < e;
*/

/*@ lemma diff_bounds:
      \forall integer a, e, k;
      0 <= a <= 123 && 0 <= e <= 123 && 0 <= k <= 123 && a < e ==>
      (e - a <= k ==> e - a >= 0);
*/

/*@ requires 0 <= a <= 123 && 0 <= b <= 123 && 0 <= c <= 123 &&
             0 <= d <= 123 && 0 <= e <= 123 && 0 <= k <= 123;
    requires is_ordered(a, b, c, d, e);
    ensures \result == true <==> e - a <= k;
    assigns \nothing;
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int diff;
    bool is_within_range;

    //@ assert a < e;
    diff = e - a;
    //@ assert diff == e - a;
    is_within_range = true;

    if (diff > k)
    {
        is_within_range = false;
    }

    //@ assert is_within_range == true <==> e - a <= k;
    return is_within_range;
}
