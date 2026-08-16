#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (x) && (x) <= 100000);
    ensures \result >= 0;
    ensures \result <= n + 1;
    assigns \nothing;
*/
int func(int n, int x)
{
    int num;
    int cnt;
    num = 1;
    cnt = 0;

    /*@
        loop invariant ((1 <= ((n)) && ((n)) <= 100 &&
        1 <= ((x)) && ((x)) <= 100000) &&
        0 <= (cnt) && (cnt) <= (n) &&
        (num) >= 1 &&
        (num) <= 100 * ((cnt) + 1));
        loop assigns cnt, num;
        loop variant n - cnt;
    */
    while (cnt < n)
    {
        //@ assert ((1 <= ((n)) && ((n)) <= 100 &&         1 <= ((x)) && ((x)) <= 100000) &&         0 <= (cnt) && (cnt) <= (n) &&         (num) >= 1 &&         (num) <= 100 * ((cnt) + 1));
        if (num <= x)
        {
            num += 100;
            cnt += 1;
        }
        else
        {
            break;
        }
    }

    //@ assert cnt >= 0;
    //@ assert cnt <= n + 1;
    return cnt;
}
