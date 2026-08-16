#include <stdbool.h>

/*@
    predicate diff_le(integer x, integer y, integer d) =
        (x > y ? x - y : y - x) <= d;
*/

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == ((a > c ? a - c : c - a) <= d || 
                       ((a > b ? a - b : b - a) <= d && (b > c ? b - c : c - b) <= d));
*/
bool func(int a, int b, int c, int d)
{
    int diff_ac;
    int diff_ab;
    int diff_bc;
    bool result;

    diff_ac = (a > c) ? (a - c) : (c - a);
    diff_ab = (a > b) ? (a - b) : (b - a);
    diff_bc = (b > c) ? (b - c) : (c - b);

    if (diff_ac <= d)
    {
        //@ assert diff_le(a, c, d);
        result = true;
    }
    else if (diff_ab <= d && diff_bc <= d)
    {
        //@ assert diff_le(a, b, d);
        //@ assert diff_le(b, c, d);
        result = true;
    }
    else
    {
        //@ assert !diff_le(a, c, d);
        //@ assert !(diff_le(a, b, d) && diff_le(b, c, d));
        result = false;
    }

    return result;
}
