#include <stdbool.h>

/*@
    requires 0 <= a && 0 <= b && 0 <= k && k <= a + b;
    ensures 0 <= \result && \result <= k;
    assigns \nothing;
*/
int func(int a, int b, int k)
{
    int k_remaining;
    int x;
    int y;
    int result;

    k_remaining = k;

    //@ assert ((k_remaining) >= 0);
    //@ assert k_remaining == k;

    if (a < k_remaining) {
        x = a;
    } else {
        x = k_remaining;
    }
    //@ assert ((x) >= 0);
    //@ assert x <= a && x <= k_remaining;

    k_remaining = k_remaining - x;
    //@ assert ((k_remaining) >= 0);
    //@ assert ((x) + (0) + (k_remaining) == (k));

    if (b < k_remaining) {
        y = b;
    } else {
        y = k_remaining;
    }
    //@ assert ((y) >= 0);
    //@ assert y <= b && y <= k_remaining;

    k_remaining = k_remaining - y;
    //@ assert ((k_remaining) >= 0);
    //@ assert ((x) + (y) + (k_remaining) == (k));

    result = x - k_remaining;
    //@ assert result == ((x) - (k_remaining));
    //@ assert result <= k;

    return result;
}
