/*@
    requires (1 <= (l) && (l) <= (r) && (r) <= 100) && (1 <= (d) && (d) <= 100);
    ensures \result >= 0 && \result <= r - l + 1;
*/
int func(int l, int r, int d)
{
    int ans = 0;
    int i = l;
    //@ ghost int old_i;
    //@ ghost int old_j;
    //@ ghost int old_ans;

    /*@
        loop invariant ((l) <= (i) && (i) <= (r) + 1 && 0 <= (ans) && (ans) <= (i) - (l) && (1 <= ((l)) && ((l)) <= ((r)) && ((r)) <= 100));
        loop assigns i, ans;
        loop variant r - i + 1;
    */
    while (i <= r)
    {
        int j = 0;
        int is_divisible = 0;

        /*@
            loop invariant (0 <= (j) && (j) <= (d) && 0 <= (ans) && (ans) <= (i) - (l) && (l) <= (i) && (i) <= (r) + 1 && (1 <= ((d)) && ((d)) <= 100));
            loop assigns j, is_divisible;
            loop variant d - j;
        */
        while (j < d)
        {
            if (i == j)
            {
                is_divisible = 1;
                break;
            }
            j++;
        }

        if (is_divisible)
        {
            ans++;
        }
        i++;
    }

    //@ assert ans <= r - l + 1;
    return ans;
}
