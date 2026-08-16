/*@
    requires (0 <= (A) && (A) <= 100 &&
        0 <= (P) && (P) <= 100);
    ensures \result >= 0;
    ensures \result <= ((A) * 3 + (P));
*/
int func(int A, int P)
{
    int ret;
    int ans;
    int is_odd;
    int temp_ret;

    ret = A * 3 + P;
    ans = 0;
    is_odd = 0;
    temp_ret = ret;

    /*@
        loop invariant (0 <= (temp_ret) && (temp_ret) <= (((A)) * 3 + ((P))) &&
        (ans) >= 0 &&
        (ans) <= ((((A)) * 3 + ((P))) - (temp_ret)) / 2 &&
        (0 <= ((A)) && ((A)) <= 100 &&
        0 <= ((P)) && ((P)) <= 100));
        loop assigns temp_ret, ans;
        loop variant temp_ret;
    */
    while (temp_ret >= 2)
    {
        //@ assert temp_ret >= 2;
        temp_ret -= 2;
        ans += 1;
    }

    if (temp_ret == 1)
    {
        is_odd = 1;
    }

    if (is_odd)
    {
        ans += 1;
    }

    //@ assert ans >= 0;
    return ans;
}
