#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result <= a + b;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int min_val;
    int ans;
    int cnt;
    int tmp;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100 &&         1 <= (c) && (c) <= 100);
    
    min_val = (c < a + b) ? c : (a + b);
    ans = 0;
    cnt = 0;
    tmp = min_val;

    /*@
        loop invariant 0 <= tmp <= min_val;
        loop invariant 0 <= cnt <= min_val / 2;
        loop invariant tmp == min_val - 2 * cnt;
        loop invariant (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100);
        loop assigns tmp, cnt;
        loop variant tmp;
    */
    while (tmp >= 2)
    {
        tmp -= 2;
        cnt += 1;
    }
    ans += cnt;

    if (tmp == 1)
    {
        ans += 1;
    }

    //@ assert ans >= 0;
    //@ assert ans <= c;
    //@ assert ans <= a + b;

    return ans;
}
