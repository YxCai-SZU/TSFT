/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0);
    requires ((a) + (b) + (c) <= 200000);
    ensures \result >= 0;
    ensures \result <= a + b + c;
*/
int func(int a, int b, int c)
{
    int ans = 0;
    int a_cnt = a;
    int b_cnt = b;
    int c_cnt = c;

    //@ assert a_cnt >= 0 && b_cnt >= 0 && c_cnt >= 0;
    //@ assert a_cnt + b_cnt + c_cnt <= 200000;

    if (c_cnt >= 1 && b_cnt >= 1 && a_cnt >= 1)
    {
        ans += 1;
        c_cnt -= 1;
        b_cnt -= 1;
        a_cnt -= 1;
        //@ assert ans == 1;
        //@ assert a_cnt + b_cnt + c_cnt == a + b + c - 3;
    }
    else
    {
        //@ assert ans == 0;
        return ans;
    }

    /*@
        loop invariant a_cnt >= 0 && b_cnt >= 0 && c_cnt >= 0;
        loop invariant ans >= 0;
        loop invariant ans <= a + b + c - (a_cnt + b_cnt + c_cnt);
        loop invariant a + b + c <= 200000;
        loop assigns ans, a_cnt, b_cnt, c_cnt;
    */
    while (a_cnt >= 1 && b_cnt >= 2 && c_cnt >= 1)
    {
        ans += 1;
        a_cnt -= 1;
        b_cnt -= 2;
        c_cnt -= 1;
        //@ assert ans <= a + b + c - (a_cnt + b_cnt + c_cnt);
    }

    if (b_cnt == 1 && c_cnt >= 1 && a_cnt >= 1)
    {
        ans += 1;
        //@ assert ans <= a + b + c;
    }

    //@ assert ans >= 0;
    //@ assert ans <= a + b + c;
    return ans;
}
