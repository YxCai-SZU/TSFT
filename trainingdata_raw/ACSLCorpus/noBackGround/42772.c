#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result == a + c || \result == b + d ||
            \result == b + c || \result == a + d;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t min_ab;
    int64_t min_cd;
    int64_t ans;

    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000) && (1 <= (d) <= 10000);

    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }

    if (c < d) {
        min_cd = c;
    } else {
        min_cd = d;
    }

    //@ assert min_ab == ((a) < (b) ? (a) : (b));
    //@ assert min_cd == ((c) < (d) ? (c) : (d));

    ans = min_ab + min_cd;

    //@ assert min_ab == a || min_ab == b;
    //@ assert min_cd == c || min_cd == d;
    //@ assert ans == a + c || ans == b + d || ans == b + c || ans == a + d;

    return ans;
}
