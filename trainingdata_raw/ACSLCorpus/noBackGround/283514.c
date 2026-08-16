/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures ((\result) == (a) * 2 || (\result) == (a) * 2 - 1 || (\result) == (b) * 2 - 1);
*/
int func(int a, int b)
{
    int ans;
    int is_a_turn;
    int a_cnt;
    int b_cnt;

    ans = 0;
    is_a_turn = 1;
    a_cnt = 0;
    b_cnt = 0;

    /*@
        loop invariant 0 <= a_cnt <= a;
        loop invariant 0 <= b_cnt <= b;
        loop invariant (3 <= (a) && (a) <= 20);
        loop invariant (3 <= (b) && (b) <= 20);
        loop invariant a_cnt + b_cnt <= a + b;
        loop assigns a_cnt, b_cnt, is_a_turn;
    */
    while (a_cnt < a && b_cnt < b)
    {
        if (is_a_turn)
        {
            a_cnt = a_cnt + 1;
            is_a_turn = 0;
        }
        else
        {
            b_cnt = b_cnt + 1;
            is_a_turn = 1;
        }
    }

    if (a_cnt == b_cnt)
    {
        ans = a * 2;
    }
    else if (a_cnt > b_cnt)
    {
        ans = a * 2 - 1;
    }
    else
    {
        ans = b * 2 - 1;
    }

    //@ assert ((ans) == (a) * 2 || (ans) == (a) * 2 - 1 || (ans) == (b) * 2 - 1);
    return ans;
}
