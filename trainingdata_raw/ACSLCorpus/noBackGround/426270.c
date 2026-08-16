#include <stdbool.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (d) >= 0 && (e) >= 0 && (k) >= 0 &&
        (a) < 124 && (b) < 124 && (c) < 124 && (d) < 124 && (e) < 124 && (k) < 124 &&
        (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == (((e) - (a)) <= k);
    assigns \nothing;
 */
bool func(int a, int b, int c, int d, int e, int k)
{
    int dist;

    //@ assert ((a) >= 0 && (b) >= 0 && (c) >= 0 && (d) >= 0 && (e) >= 0 && (k) >= 0 &&         (a) < 124 && (b) < 124 && (c) < 124 && (d) < 124 && (e) < 124 && (k) < 124 &&         (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    dist = e - a;
    //@ assert dist == ((e) - (a));
    return dist <= k;
}
