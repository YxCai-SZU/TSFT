#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bounds:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> 
            1 <= product(x, y) <= 10000 * 10000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == a * b || \result == c * d;
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d) {
    // Declare all variables at the top
    int sa;
    int sc;
    int ans;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);

    //@ assert a * b <= 10000 * 10000;
    //@ assert c * d <= 10000 * 10000;

    sa = a * b;
    sc = c * d;

    //@ assert sa >= 1;
    //@ assert sc >= 1;

    if (sa > sc) {
        ans = sa;
    } else {
        ans = sc;
    }

    //@ assert ans == sa || ans == sc;
    return ans;
}
