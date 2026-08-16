#include <stdbool.h>

/*@
    predicate are_ordered(integer a, integer b, integer c, integer d, integer e) =
        a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0 &&
        a < b && b < c && c < d && d < e;
*/

/*@
    requires are_ordered(a, b, c, d, e) && k >= 0;
    ensures \result == true <==> (e - a <= k);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int ans;

    //@ assert are_ordered(a, b, c, d, e);
    //@ assert k >= 0;

    if (e - a > k) {
        ans = 0;
    } else {
        ans = 1;
    }

    //@ assert ans == 1 <==> (e - a <= k);
    return ans == 1;
}
