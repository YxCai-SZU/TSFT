#include <limits.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 1000;

    logic integer sum_abc(integer a, integer b, integer c) = a + b + c;
    logic integer sum_acd(integer a, integer c, integer d) = a + c + d;
    logic integer sum_abd(integer a, integer b, integer d) = a + b + d;
    logic integer sum_bcd(integer b, integer c, integer d) = b + c + d;

    lemma result_cases:
        \forall integer a, b, c, d, res;
        valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) &&
        (res == sum_abc(a,b,c) || res == sum_acd(a,c,d) || 
         res == sum_abd(a,b,d) || res == sum_bcd(b,c,d)) ==>
        res >= 0;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result >= 0;
    ensures \result == sum_abc(a,b,c) || \result == sum_acd(a,c,d) || 
            \result == sum_abd(a,b,d) || \result == sum_bcd(b,c,d);
*/
int func(int a, int b, int c, int d) {
    int res;

    if (a < b) {
        if (b < c) {
            if (c < d) {
                res = a + b + c;
            } else {
                res = a + b + d;
            }
        } else {
            if (b < d) {
                res = a + c + d;
            } else {
                res = a + b + d;
            }
        }
    } else {
        if (a < c) {
            if (c < d) {
                res = a + b + c;
            } else {
                res = b + c + d;
            }
        } else {
            if (a < d) {
                res = a + b + d;
            } else {
                res = b + c + d;
            }
        }
    }

    //@ assert res == sum_abc(a,b,c) || res == sum_acd(a,c,d) || res == sum_abd(a,b,d) || res == sum_bcd(b,c,d);
    return res;
}
