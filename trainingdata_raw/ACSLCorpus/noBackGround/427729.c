#include <limits.h>

/*@
    requires (0 <= (a) && 0 <= (b) && 0 <= (c) &&
        1 <= (k) && (k) <= (a) + (b) + (c) && (k) <= 2000000000);
    ensures \result <= a;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int sum = a;
    int cnt = a;
    int b_div_2 = 0;
    int temp_b = b;
    int c_div_2 = 0;
    int temp_c = c;
    int ans = 0;
    int temp_cnt = 0;

    //@ assert 0 <= temp_b <= b;
    //@ assert b_div_2 <= ((b) / 2);
    /*@
        loop invariant 0 <= temp_b <= b;
        loop invariant b_div_2 <= ((b) / 2);
        loop invariant temp_b == b - 2 * b_div_2;
        loop assigns temp_b, b_div_2;
        loop variant temp_b;
    */
    while (temp_b >= 2)
    {
        temp_b -= 2;
        b_div_2 += 1;
    }

    cnt -= b_div_2;
    if (cnt < 0)
    {
        cnt = 0;
    }

    //@ assert 0 <= temp_c <= c;
    //@ assert c_div_2 <= ((c) / 2);
    /*@
        loop invariant 0 <= temp_c <= c;
        loop invariant c_div_2 <= ((c) / 2);
        loop invariant temp_c == c - 2 * c_div_2;
        loop assigns temp_c, c_div_2;
        loop variant temp_c;
    */
    while (temp_c >= 2)
    {
        temp_c -= 2;
        c_div_2 += 1;
    }

    cnt -= c_div_2;
    if (cnt < 0)
    {
        cnt = 0;
    }

    temp_cnt = cnt;
    //@ assert 0 <= temp_cnt <= cnt;
    //@ assert ans <= a;
    //@ assert temp_cnt + ans <= a;
    /*@
        loop invariant 0 <= temp_cnt <= cnt;
        loop invariant ans <= a;
        loop invariant temp_cnt + ans <= a;
        loop assigns temp_cnt, ans;
        loop variant temp_cnt;
    */
    while (temp_cnt > 0)
    {
        temp_cnt -= 1;
        ans += 1;
    }

    return ans;
}
