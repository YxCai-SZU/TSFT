#include <stdint.h>

/*@ predicate in_range(integer x) = 0 <= x <= 123; */
/*@ predicate strict_order(integer a, integer b, integer c, integer d, integer e) =
      a < b && b < c && c < d && d < e; */

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d) && in_range(e) && in_range(k);
    requires strict_order(a, b, c, d, e);
    ensures \result == e - a || \result == -1;
    ensures \result >= 0 || \result == -1;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d, int64_t e, int64_t k) {
    int64_t t;
    int64_t res;

    t = e - a;
    //@ assert t == e - a;
    
    if (t <= k) {
        //@ assert t <= k;
        res = e - a;
        //@ assert res == e - a;
        //@ assert res >= 0;
        return res;
    } else {
        //@ assert t > k;
        res = -1;
        //@ assert res == -1;
        return res;
    }
}
