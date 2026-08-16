#include <stddef.h>

/*@
    requires (1 <= (a) && (a) <= 100000 &&
        1 <= (b) && (b) <= 100000 &&
        1 <= (c) && (c) <= 100000 &&
        1 <= (k) && (k) <= 100000 &&
        (a) + (b) + (c) >= (k));
    ensures 0 <= \result && \result <= a;
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t c, size_t k)
{
    size_t ans = 0;
    size_t ca = a;
    size_t t = k;
    size_t min1;
    size_t min2;
    size_t min3;

    //@ assert (1 <= (a) && (a) <= 100000 &&         1 <= (b) && (b) <= 100000 &&         1 <= (c) && (c) <= 100000 &&         1 <= (k) && (k) <= 100000 &&         (a) + (b) + (c) >= (k));

    // Manually implement min function
    if (a < k) {
        min1 = a;
    } else {
        min1 = k;
    }
    //@ assert min1 == (((a) < (k)) ? (a) : (k));
    ans += min1;
    //@ assert ans == min1;
    //@ assert t == k;
    t -= min1;
    //@ assert t == k - min1;

    // Manually implement min function
    if (b < t) {
        min2 = b;
    } else {
        min2 = t;
    }
    //@ assert min2 == (((b) < (t)) ? (b) : (t));
    //@ assert t == k - min1;
    t -= min2;
    //@ assert t == k - min1 - min2;

    // Manually implement min function
    if (c < t) {
        min3 = c;
    } else {
        min3 = t;
    }
    //@ assert min3 == (((c) < (t)) ? (c) : (t));
    //@ assert t == k - min1 - min2;
    t -= min3;
    //@ assert t == k - min1 - min2 - min3;

    // Implement subtraction manually
    //@ assert ans == min1;
    ans = ans - t;
    //@ assert ans == min1 - t;

    //@ assert ans >= 0;
    //@ assert ans <= a;
    return ans;
}
