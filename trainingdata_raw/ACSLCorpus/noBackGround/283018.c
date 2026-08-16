/*@
    requires (1 <= (n) <= 100);
    ensures \result == (((n) + 1) / 2);
    assigns \nothing;
*/
unsigned int func(unsigned int n)
{
    unsigned int result = 0;
    unsigned int temp_n = n;

    /*@
        loop invariant 0 <= result <= n / 2;
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n == n - 2 * result;
        loop invariant (1 <= (n) <= 100);
        loop assigns result, temp_n;
        loop variant temp_n;
    */
    while (temp_n > 1)
    {
        temp_n -= 2;
        result += 1;
    }

    if (temp_n == 1)
    {
        result += 1;
    }

    //@ assert result == (((n) + 1) / 2);
    return result;
}
