#include <stdint.h>
#include <limits.h>

/*@
    requires (1 <= (a) <= 10000 &&
        1 <= (b) <= 10000 &&
        1 <= (c) <= 10000 &&
        1 <= (d) <= 10000);
    ensures \result >= 0 || \result == -1;
    ensures \result == -1 || (integer)\result <= a + b + c + d;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t m1;
    uint32_t m2;
    uint32_t m;
    uint32_t ans;

    //@ assert (1 <= (a) <= 10000 &&         1 <= (b) <= 10000 &&         1 <= (c) <= 10000 &&         1 <= (d) <= 10000);

    if (a > b) {
        m1 = a - b;
        //@ assert m1 == a - b;
    } else {
        m1 = b - a;
        //@ assert m1 == b - a;
    }

    if (c > d) {
        m2 = c - d;
        //@ assert m2 == c - d;
    } else {
        m2 = d - c;
        //@ assert m2 == d - c;
    }

    if (m1 > m2) {
        m = m1;
        //@ assert m == m1;
    } else {
        m = m2;
        //@ assert m == m2;
    }

    //@ assert m == (\let m1 = ((a) > (b)) ? (a) - (b) : (b) - (a);         \let m2 = ((c) > (d)) ? (c) - (d) : (d) - (c);         (m1 > m2) ? m1 : m2);
    //@ assert m >= 0;

    if (m == 0) {
        //@ assert a == b && c == d;
        return 0;
    }

    ans = a + b + c + d - m;
    //@ assert ans == a + b + c + d - m;

    if (ans <= INT32_MAX) {
        //@ assert ans <= a + b + c + d;
        return (int32_t)ans;
    } else {
        //@ assert ans > INT32_MAX;
        return -1;
    }
}
