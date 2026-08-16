#include <stdbool.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (d) >= 0 && (e) >= 0 &&
        (a) < 124 && (b) < 124 && (c) < 124 && (d) < 124 && (e) < 124 &&
        (k) >= 0 && (k) < 124);
    ensures \result == true <==> (b - a <= k && c - b <= k && d - c <= k && e - d <= k);
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long p;
    int i;

    p = a;
    i = 0;

    /*@
        loop invariant 0 <= i <= 4;
        loop invariant p == a || p == b || p == c || p == d || p == e;
        loop invariant ((a) >= 0 && (b) >= 0 && (c) >= 0 && (d) >= 0 && (e) >= 0 &&
        (a) < 124 && (b) < 124 && (c) < 124 && (d) < 124 && (e) < 124 &&
        (k) >= 0 && (k) < 124);
        loop invariant (i == 0 ==> p == a) && (i == 1 ==> p == b) && (i == 2 ==> p == c) && (i == 3 ==> p == d) && (i == 4 ==> p == e);
        loop invariant (i > 0 ==> b - a <= k) && (i > 1 ==> c - b <= k) && (i > 2 ==> d - c <= k) && (i > 3 ==> e - d <= k);
        loop assigns p, i;
    */
    while (i < 4)
    {
        long next;

        //@ assert 0 <= i && i <= 3;
        if (i == 0) {
            next = b;
        } else if (i == 1) {
            next = c;
        } else if (i == 2) {
            next = d;
        } else {
            next = e;
        }

        //@ assert next == ((i) == 0 ? (b) :         (i) == 1 ? (c) :         (i) == 2 ? (d) :         (e));
        if (next - p > k) {
            return false;
        }

        p = next;
        i = i + 1;
    }

    //@ assert i == 4;
    //@ assert b - a <= k && c - b <= k && d - c <= k && e - d <= k;
    return true;
}
