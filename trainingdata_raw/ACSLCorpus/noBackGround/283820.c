#include <limits.h>

/*@
    requires INT_MIN <= a <= INT_MAX && INT_MIN <= b <= INT_MAX;
    ensures ((\result) >= (a) && (\result) >= (b) && ((\result) == (a) || (\result) == (b)));
*/
int maximum_int(int a, int b) {
    int ret;
    if (a > b) {
        ret = a;
    } else {
        ret = b;
    }
    //@ assert ((ret) >= (a) && (ret) >= (b) && ((ret) == (a) || (ret) == (b)));
    return ret;
}

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (c) <= 100 &&
        1 <= (k) <= 3 && (k) <= (a) + (b) + (c));
    ensures ((\result) <= (a) + (b) + (c) && (\result) <= (k));
*/
int func(int a, int b, int c, int k) {
    int total;
    int k_remaining;
    total = 0;
    k_remaining = k;

    //@ assert total <= a + b + c;
    //@ assert total <= k;

    if (a < k_remaining) {
        total += a;
        k_remaining -= a;
    } else {
        total += k_remaining;
        k_remaining = 0;
    }

    //@ assert total <= a + b + c;
    //@ assert total <= k;

    if (b < k_remaining) {
        k_remaining -= b;
    } else {
        k_remaining = 0;
    }

    //@ assert total <= a + b + c;
    //@ assert total <= k;

    if (c < k_remaining) {
        total -= k_remaining;
    }

    //@ assert total <= a + b + c;
    //@ assert total <= k;

    return total;
}
