#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer min(integer x, integer y) = x < y ? x : y;

    lemma ans_bounds:
        \forall integer a, b, c, d, min1, min2, ans;
        valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) &&
        min1 == min(a, b) && min2 == min(c, d) &&
        ans == min(min1, min2) + min1 ==>
        ans >= 0 && ans <= a + b + c + d;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result >= 0;
    ensures \result <= a + b + c + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int ans;
    int min1;
    int min2;

    ans = 0;

    //@ assert valid_range(a) && valid_range(b);
    min1 = a < b ? a : b;

    //@ assert valid_range(c) && valid_range(d);
    min2 = c < d ? c : d;

    //@ assert min1 == min(a, b) && min2 == min(c, d);
    ans += min1 < min2 ? min1 : min2;
    ans += min1;

    //@ assert ans >= 0;
    //@ assert ans <= a + b + c + d;
    return ans;
}
