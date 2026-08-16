#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 0 <= x <= 23;

    logic integer total_minutes(integer hours, integer minutes) = hours * 60 + minutes;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c) && is_valid_range(d);
    ensures \result == true <==> total_minutes(a, b) >= total_minutes(c, d);
*/
bool func(int a, int b, int c, int d)
{
    int s = 0;
    int t = 0;
    int a_minutes = 0;
    int b_minutes = 0;
    int c_minutes = 0;
    int d_minutes = 0;

    a_minutes = a * 60;
    b_minutes = b;
    c_minutes = c * 60;
    d_minutes = d;

    //@ assert a_minutes == a * 60;
    //@ assert b_minutes == b;
    //@ assert c_minutes == c * 60;
    //@ assert d_minutes == d;

    s = a_minutes + b_minutes;
    t = c_minutes + d_minutes;

    //@ assert s == total_minutes(a, b);
    //@ assert t == total_minutes(c, d);

    return s >= t;
}
