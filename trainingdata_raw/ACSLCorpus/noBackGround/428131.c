#include <stdint.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    ensures \result == n * a || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t a, int64_t b)
{
    // Variable declarations at scope top
    int64_t ret;

    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 50;
    //@ assert 1 <= b && b <= 50;

    //@ assert n * a <= 1000;

    if (n * a < b) {
        ret = n * a;
    } else {
        ret = b;
    }

    //@ assert ret == n * a || ret == b;
    //@ assert ret <= b;

    return ret;
}
