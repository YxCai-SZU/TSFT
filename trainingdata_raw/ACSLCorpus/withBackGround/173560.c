#include <limits.h>

/*@
    predicate bounds(integer v) = 1 <= v && v <= 100;
    predicate bounds_product(integer v) = 1 <= v && v <= 10000;
*/

/*@
    requires x != y;
    requires bounds(x);
    requires bounds(y);
    ensures bounds(\result);
*/
int func(int x, int y) {
    int abs_val;
    int ans;

    //@ assert bounds(x);
    //@ assert bounds(y);
    //@ assert bounds_product(x * y);

    if (x + y < 0) {
        abs_val = -(x + y);
    } else {
        abs_val = x + y;
    }

    if (x * y < 0 || (x * y == 0 && x > y)) {
        ans = abs_val + 1;
        //@ assert ans == abs_val + 1;
        //@ assert bounds(ans);
    } else if (x <= y) {
        ans = y - x + 1;
        //@ assert ans == y - x + 1;
        //@ assert bounds(ans);
    } else {
        ans = x - y + 1;
        //@ assert ans == x - y + 1;
        //@ assert bounds(ans);
    }

    return ans;
}
