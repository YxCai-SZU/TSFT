#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
*/

/*@
    requires valid_range(d) && valid_range(t) && valid_range(s);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    unsigned int d_unsigned;
    unsigned int t_unsigned;
    unsigned int s_unsigned;
    unsigned int product;

    //@ assert 1 <= d <= 10000;
    //@ assert 1 <= t <= 10000;
    //@ assert 1 <= s <= 10000;

    d_unsigned = (d < 0) ? (unsigned int)(-d) : (unsigned int)d;
    t_unsigned = (t < 0) ? (unsigned int)(-t) : (unsigned int)t;
    s_unsigned = (s < 0) ? (unsigned int)(-s) : (unsigned int)s;

    //@ assert t_unsigned <= 10000;
    //@ assert s_unsigned <= 10000;
    //@ assert t_unsigned * s_unsigned <= 100000000;

    product = t_unsigned * s_unsigned;

    //@ assert product == t_unsigned * s_unsigned;
    //@ assert d_unsigned == (unsigned int)((d < 0) ? -d : d);

    return (d_unsigned <= product) ? true : false;
}
