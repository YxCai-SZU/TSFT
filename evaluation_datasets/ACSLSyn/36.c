#include <stdbool.h>

/*@
    predicate is_strictly_increasing(integer a, integer b, integer c, integer d) =
        a < b && b < c && c < d;
 */

/*@
    predicate is_sorted_and_bounded(integer a, integer b, integer c, integer d, integer e, integer k) =
        a <= b && b <= c && c <= d && d <= e && e - a <= k;
 */

/*@
    predicate valid_window(integer a, integer b, integer c, integer d, integer e, integer f, integer g, integer h, integer i, integer k) =
        is_strictly_increasing(a, b, c, d) && is_sorted_and_bounded(e, f, g, h, i, k);
 */

bool func_strict_increasing(int a, int b, int c, int d)
{
    bool result;

    if (a >= b)
    {
        //@ assert a >= b || b >= c || c >= d;
        result = false;
        return result;
    }
    if (b >= c)
    {
        //@ assert a >= b || b >= c || c >= d;
        result = false;
        return result;
    }
    if (c >= d)
    {
        //@ assert a >= b || b >= c || c >= d;
        result = false;
        return result;
    }

    //@ assert is_strictly_increasing(a, b, c, d);
    result = true;
    return result;
}

bool func_sorted_bounded(int a, int b, int c, int d, int e, int k)
{
    //@ assert 0 <= a <= 123;
    //@ assert 0 <= b <= 123;
    //@ assert 0 <= c <= 123;
    //@ assert 0 <= d <= 123;
    //@ assert 0 <= e <= 123;
    //@ assert 0 <= k <= 123;

    if (a <= b && b <= c && c <= d && d <= e && e - a <= k) {
        //@ assert is_sorted_and_bounded(a, b, c, d, e, k);
        return true;
    } else {
        //@ assert !is_sorted_and_bounded(a, b, c, d, e, k);
        return false;
    }
}

bool validate_time_window(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, int y5, int k)
{

    bool increasing = func_strict_increasing(x1, x2, x3, x4);
    bool bounded = func_sorted_bounded(y1, y2, y3, y4, y5, k);

    bool result = increasing && bounded;

    //@ assert result == true ==> (is_strictly_increasing(x1, x2, x3, x4) && is_sorted_and_bounded(y1, y2, y3, y4, y5, k));
    //@ assert result == false ==> (!is_strictly_increasing(x1, x2, x3, x4) || !is_sorted_and_bounded(y1, y2, y3, y4, y5, k));
    //@ assert valid_window(x1, x2, x3, x4, y1, y2, y3, y4, y5, k) <==> result;

    return result;
}
