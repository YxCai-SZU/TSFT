/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 20 && 1 <= m <= 20;

    logic integer loop_decrease(integer m, integer i) =
        m - i + 1;
*/

/*@
    requires valid_range(n, m);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n, int m)
{
    int result = n;
    int i = 1;

    /*@
        loop invariant 1 <= i <= m + 1;
        loop invariant result >= 0 && result <= n;
        loop assigns result, i;
        loop variant m - i + 1;
    */
    while (i <= m)
    {
        //@ assert result >= 0 && result <= n;
        if (result >= i)
        {
            result -= i;
        }
        i += 1;
    }
    return result;
}

int main()
{
    return 0;
}
