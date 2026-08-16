#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer max_of_three(integer x, integer y, integer z) =
        (x >= y && x >= z) ? x : ((y >= z) ? y : z);

    lemma multiplication_bounds:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> 1 <= x * y <= 10000;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    requires valid_range(d);
    ensures \result == b * d || \result == c * d || \result == a * c;
    ensures 1 <= \result <= 10000;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Variable declarations at scope top
    int max1;
    int max2;
    int bd;
    int cd;
    int ac;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);

    // Calculate products with overflow protection
    bd = b * d;
    cd = c * d;
    ac = a * c;

    //@ assert 1 <= bd <= 10000;
    //@ assert 1 <= cd <= 10000;
    //@ assert 1 <= ac <= 10000;

    // First comparison
    if (bd > cd) {
        max1 = bd;
    } else {
        max1 = cd;
    }

    //@ assert max1 == bd || max1 == cd;
    //@ assert 1 <= max1 <= 10000;

    // Second comparison
    if (max1 > ac) {
        max2 = max1;
    } else {
        max2 = ac;
    }

    //@ assert max2 == max1 || max2 == ac;
    //@ assert max2 == bd || max2 == cd || max2 == ac;
    //@ assert 1 <= max2 <= 10000;

    return max2;
}
