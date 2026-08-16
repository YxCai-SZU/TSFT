/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (k) && (k) <= 100 &&
        (n) >= 0 &&
        (k) >= 0);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(int n, int k)
{
    int result;
    int remainder;

    result = 0;
    remainder = n;

    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant 1 <= k && k <= 100;
        loop invariant n >= 0;
        loop invariant k >= 0;
        loop invariant 0 <= remainder && remainder <= n;
        loop invariant remainder >= 0;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= k)
    {
        remainder -= k;
    }

    if (remainder == 0)
    {
        result = 0;
    }
    else
    {
        result = 1;
    }

    //@ assert result == 0 || result == 1;

    return result;
}
