#include <stdint.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;

    logic integer min(integer x, integer y) = x < y ? x : y;
    logic integer max(integer x, integer y) = x < y ? y : x;

    lemma min_bound: \forall integer x, y; min(x, y) <= x && min(x, y) <= y;
    lemma max_bound: \forall integer x, y; x <= max(x, y) && y <= max(x, y);
    lemma sum_nonneg: \forall integer a, b, c, d; 
        valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==> 
        0 <= a + b + c + d;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result >= 0;
    ensures \result <= a + b + c + d;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t x;
    int64_t sa;
    int64_t sc;
    int64_t l;
    int64_t tmp;

    x = 0;

    //@ assert valid_range(a) && valid_range(b);
    sa = a < b ? a : b;

    //@ assert valid_range(c) && valid_range(d);
    sc = c < d ? c : d;

    //@ assert sa <= a && sa <= b;
    //@ assert sc <= c && sc <= d;
    l = (sa + sc) < (a + c) ? (sa + sc) : (a + c);

    //@ assert l <= sa + sc && l <= a + c;
    x += l < (b + d) ? l : (b + d);

    //@ assert x >= 0;
    tmp = (a + c) - l;
    if (tmp < 0)
    {
        tmp = 0;
    }

    //@ assert tmp >= 0;
    x += tmp;

    //@ assert x >= 0;
    //@ assert x <= a + b + c + d;
    return x;
}
