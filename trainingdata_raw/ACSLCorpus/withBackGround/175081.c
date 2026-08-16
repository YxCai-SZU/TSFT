#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer max(integer x, integer y) = (x > y) ? x : y;

    lemma max_ge_zero:
        \forall integer x, y;
        (x >= 0 || y >= 0) ==> max(x, y) >= 0;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == (b >= c || a >= d);
*/
bool func(int a, int b, int c, int d)
{
    int diff_b_c;
    int diff_a_d;
    int max_val;

    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= d && d <= 100;

    diff_b_c = b - c;
    diff_a_d = a - d;

    if (diff_b_c > diff_a_d)
    {
        max_val = diff_b_c;
    }
    else
    {
        max_val = diff_a_d;
    }

    //@ assert max_val == max(diff_b_c, diff_a_d);
    //@ assert max_val >= 0 <==> (b >= c || a >= d);

    return max_val >= 0;
}
