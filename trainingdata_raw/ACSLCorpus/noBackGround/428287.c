/*@
    requires (1 <= (x) <= 1000);
    ensures \result >= 1 && \result <= x;
    assigns \nothing;
*/
int func(int x)
{
    int res;
    int i;
    int tmp;

    res = 1;
    i = 1;

    /*@
        loop invariant (1 <= (i) <= 1001 &&
        (res) >= 1 &&
        (res) <= (x) &&
        (1 <= ((x)) <= 1000));
        loop assigns i, res, tmp;
        loop variant 1001 - i;
    */
    while (i <= 1000)
    {
        tmp = res + 6 * i;
        if (tmp < x)
        {
            res += 6 * i;
        }
        else
        {
            break;
        }
        i += 1;
    }

    //@ assert res >= 1 && res <= x;
    return res;
}
