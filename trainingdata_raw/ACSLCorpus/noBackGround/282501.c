/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures \result >= 0 && \result <= 201;
    assigns \nothing;
*/
int func(int n, int m)
{
    int max_val;
    int i;
    int new_val;

    //@ assert (1 <= (n) <= 100 && 1 <= (m) <= 100);
    max_val = (n * 2 + m > 100) ? 100 : (n * 2 + m);
    //@ assert max_val >= 0 && max_val <= 201;

    i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant max_val >= 0 && max_val <= 201;
        loop invariant (1 <= (n) <= 100 && 1 <= (m) <= 100);
        loop assigns i, max_val, new_val;
        loop variant n - i;
    */
    while (i < n)
    {
        new_val = max_val - 2;
        //@ assert new_val == max_val - 2;

        if (new_val < 0)
        {
            //@ assert max_val >= 0 && max_val <= 201;
            break;
        }

        max_val = new_val;
        //@ assert max_val >= 0 && max_val <= 201;

        i = i + 1;
        //@ assert 0 <= i <= n;
    }

    //@ assert max_val >= 0 && max_val <= 201;
    return max_val;
}
