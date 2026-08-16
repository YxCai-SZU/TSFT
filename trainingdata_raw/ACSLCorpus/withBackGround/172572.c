#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    predicate valid_input(integer a, integer b, integer c, integer d) =
        valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) &&
        a <= b && c <= d;
    predicate is_possible_result(integer r, integer a, integer b, integer c, integer d) =
        r == a * c || r == a * d || r == b * c || r == b * d;
*/

/*@
    requires valid_input(a, b, c, d);
    ensures \result >= 0;
    ensures is_possible_result(\result, a, b, c, d);
*/
int func(int a, int b, int c, int d)
{
    int ac;
    int bd;
    int ad;
    int bc;
    int max_value;

    //@ assert a >= 1 && a <= 10000;
    //@ assert b >= 1 && b <= 10000;
    //@ assert c >= 1 && c <= 10000;
    //@ assert d >= 1 && d <= 10000;
    //@ assert a <= b;
    //@ assert c <= d;

    ac = a * c;
    bd = b * d;
    ad = a * d;
    bc = b * c;

    //@ assert ac <= 10000 * 10000;
    //@ assert bd <= 10000 * 10000;
    //@ assert ad <= 10000 * 10000;
    //@ assert bc <= 10000 * 10000;

    if (ac > bd)
    {
        if (ac > ad)
        {
            if (ac > bc)
            {
                max_value = ac;
            }
            else
            {
                max_value = bc;
            }
        }
        else
        {
            if (ad > bc)
            {
                max_value = ad;
            }
            else
            {
                max_value = bc;
            }
        }
    }
    else
    {
        if (bd > ad)
        {
            if (bd > bc)
            {
                max_value = bd;
            }
            else
            {
                max_value = bc;
            }
        }
        else
        {
            if (ad > bc)
            {
                max_value = ad;
            }
            else
            {
                max_value = bc;
            }
        }
    }

    //@ assert max_value >= 0;
    //@ assert is_possible_result(max_value, a, b, c, d);
    return max_value;
}
