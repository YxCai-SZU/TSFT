#include <stdbool.h>

/*@
    requires ((a) >= 0) && ((b) >= 0) && ((c) >= 0);
    requires (1 <= (k) && (k) <= (a) + (b) + (c));
    ensures ((\result) <= (a) + (b) + (c));
*/
long func(long a, long b, long c, long k)
{
    long cnt;
    long res;
    bool is_cnt;
    long a_cnt;
    long b_cnt;
    long c_cnt;

    cnt = k;
    res = 0;
    is_cnt = true;

    //@ assert cnt == k && res == 0 && is_cnt == true;

    a_cnt = (cnt < a) ? cnt : a;
    res = res + a_cnt;
    cnt = cnt - a_cnt;
    if (cnt == 0) {
        is_cnt = false;
    }

    //@ assert res <= a && cnt >= 0;

    b_cnt = (cnt < b) ? cnt : b;
    cnt = cnt - b_cnt;
    if (cnt == 0) {
        is_cnt = false;
    }

    //@ assert res <= a + b && cnt >= 0;

    c_cnt = (cnt < c) ? cnt : c;
    res = res - c_cnt;
    cnt = cnt - c_cnt;
    if (cnt == 0) {
        is_cnt = false;
    }

    //@ assert res <= a + b && cnt >= 0;

    if (is_cnt) {
        //@ assert cnt > 0;
        res = res + cnt;
    }

    //@ assert res <= ((a) + (b) + (c));
    return res;
}
