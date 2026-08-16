#include <limits.h>

/*@
    predicate is_valid_range(integer v) = 1 <= v <= 5000;

    logic integer min(integer x, integer y) = (x < y) ? x : y;

    logic integer total_sum(integer a, integer b, integer c, integer d) = a + b + c + d;

    lemma min_sum_bound:
        \forall integer a,b,c,d, min1, min2;
        is_valid_range(a) && is_valid_range(b) &&
        is_valid_range(c) && is_valid_range(d) &&
        min1 == min(a,b) && min2 == min(c,d) ==>
        min1 + min2 >= 0 && min1 + min2 <= total_sum(a,b,c,d);
*/

/*@
    requires is_valid_range(a) && is_valid_range(b) &&
             is_valid_range(c) && is_valid_range(d);
    ensures \result >= 0;
    ensures \result <= a + b + c + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int min1;
    int min2;
    int ans;

    //@ assert a >= 1 && a <= 5000;
    //@ assert b >= 1 && b <= 5000;
    //@ assert c >= 1 && c <= 5000;
    //@ assert d >= 1 && d <= 5000;

    if (a < b) {
        min1 = a;
    } else {
        min1 = b;
    }

    if (c < d) {
        min2 = c;
    } else {
        min2 = d;
    }

    ans = min1 + min2;

    //@ assert min1 >= 0;
    //@ assert min2 >= 0;
    //@ assert ans >= 0;

    //@ assert min1 <= a + b;
    //@ assert min2 <= c + d;
    //@ assert ans <= a + b + c + d;

    return ans;
}
