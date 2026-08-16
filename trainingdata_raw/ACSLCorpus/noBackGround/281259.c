#include <stdint.h>

/*@
    requires (0 <= (a) && 0 <= (b) && 0 <= (c) &&
        1 <= (k) && (k) <= (a) + (b) + (c) && (k) <= 2000000000);
    ensures \result <= k;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t cnt = 0;
    int64_t rst = k;

    /*@
        loop invariant (0 <= (cnt) && (cnt) <= (k) &&
        (rst) >= 0 && (rst) <= (k) &&
        (rst) + (cnt) == (k) &&
        0 <= (a) && 0 <= (b) && 0 <= (c) &&
        1 <= (k));
        loop invariant rst >= 0;
        loop assigns cnt, rst;
        loop variant rst;
    */
    while (rst > 0)
    {
        //@ assert cnt < k;
        rst -= 1;
        cnt += 1;
    }

    int64_t ans = cnt - rst;
    //@ assert ans == cnt - rst;
    return ans;
}
