#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer max(integer x, integer y) = (x > y) ? x : y;

    lemma max_property:
        \forall integer a, b, c, d;
            valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==>
            (max(a,b) + max(c,d) == a + c) ||
            (max(a,b) + max(c,d) == a + d) ||
            (max(a,b) + max(c,d) == b + c) ||
            (max(a,b) + max(c,d) == b + d);

    lemma sum_bounds:
        \forall integer a, b, c, d;
            valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==>
            2 <= max(a,b) + max(c,d) <= 200;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
    ensures 2 <= \result <= 200;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t max_ab;
    int64_t max_cd;
    int64_t ans;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);

    if (a > b) {
        max_ab = a;
    } else {
        max_ab = b;
    }

    if (c > d) {
        max_cd = c;
    } else {
        max_cd = d;
    }

    //@ assert a <= max_ab && b <= max_ab;
    //@ assert c <= max_cd && d <= max_cd;
    //@ assert 1 <= max_ab <= 100;
    //@ assert 1 <= max_cd <= 100;

    ans = max_ab + max_cd;

    //@ assert max_ab + max_cd <= 200;
    //@ assert ans == a + c || ans == a + d || ans == b + c || ans == b + d;

    return ans;
}
