#include <limits.h>

/*@
    requires (0 <= (a) && 0 <= (b) && 0 <= (c) &&
        1 <= (k) && (k) <= (a) + (b) + (c) && (k) <= 2000000000);
    ensures \result <= k;
    ensures \result == ((k) <= (a) ? (k) :
        (k) <= (a) + (b) ? (a) :
        (a) - ((k) - (a) - (b)));
*/
int func(int a, int b, int c, int k) {
    int ans = 0;
    int k_remaining = k;

    // Use all the A cards we have
    if (k_remaining <= a) {
        ans += k_remaining;
        //@ assert ans == ((k) <= (a) ? (k) :         (k) <= (a) + (b) ? (a) :         (a) - ((k) - (a) - (b)));
        return ans;
    }

    k_remaining -= a;
    ans += a;

    // Use all the B cards we have
    if (k_remaining <= b) {
        //@ assert ans == ((k) <= (a) ? (k) :         (k) <= (a) + (b) ? (a) :         (a) - ((k) - (a) - (b)));
        return ans;
    }

    k_remaining -= b;
    ans -= k_remaining;

    //@ assert ans == ((k) <= (a) ? (k) :         (k) <= (a) + (b) ? (a) :         (a) - ((k) - (a) - (b)));
    return ans;
}
