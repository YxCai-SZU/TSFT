#include <limits.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (k) >= 1 &&
        (k) <= (a) + (b) + (c) &&
        (a) + (b) + (c) <= 2000000000);
    ensures \result >= -c && \result <= a;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int k_flag;
    int cnt;
    int tmp;
    int i;

    k_flag = 0;
    cnt = 0;
    tmp = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= a;
        loop invariant 0 <= k_flag <= k;
        loop invariant 0 <= cnt <= i;
        loop invariant tmp == 0;
        loop assigns i, k_flag, cnt;
        loop variant a - i;
    */
    while (i < a)
    {
        if (k_flag == k)
        {
            break;
        }
        cnt = cnt + 1;
        k_flag = k_flag + 1;
        i = i + 1;
    }

    i = 0;

    /*@
        loop invariant 0 <= i <= b;
        loop invariant 0 <= k_flag <= k;
        loop invariant 0 <= cnt <= a;
        loop invariant tmp == 0;
        loop assigns i, k_flag;
        loop variant b - i;
    */
    while (i < b)
    {
        if (k_flag == k)
        {
            break;
        }
        k_flag = k_flag + 1;
        i = i + 1;
    }

    i = 0;

    /*@
        loop invariant 0 <= i <= c;
        loop invariant 0 <= k_flag <= k;
        loop invariant 0 <= cnt <= a;
        loop invariant -i <= tmp <= 0;
        loop assigns i, k_flag, tmp;
        loop variant c - i;
    */
    while (i < c)
    {
        if (k_flag == k)
        {
            break;
        }
        tmp = tmp - 1;
        k_flag = k_flag + 1;
        i = i + 1;
    }

    //@ assert tmp <= 0;
    //@ assert cnt >= 0 && cnt <= a;
    //@ assert tmp >= -c && tmp <= 0;

    return cnt + tmp;
}
