#include <limits.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == a * b / 2;
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int ans;
    int cnt;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    //@ assert 1 <= a * b <= 10000;

    ans = a * b;
    cnt = 0;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 0 <= ans <= a * b;
        loop invariant 0 <= cnt <= (a * b - ans) / 2;
        loop invariant ans == a * b - 2 * cnt;
        loop invariant 1 <= a * b <= 10000;
        loop assigns ans, cnt;
        loop variant ans;
    */
    while (ans >= 2)
    {
        //@ assert ans >= 2;
        ans -= 2;
        cnt += 1;
        //@ assert ans == a * b - 2 * cnt;
    }

    //@ assert ans == a * b - 2 * cnt;
    //@ assert ans < 2;
    //@ assert cnt == a * b / 2;

    return cnt;
}
