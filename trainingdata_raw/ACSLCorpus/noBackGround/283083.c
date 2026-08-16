/*@
    requires (1 <= (n) <= 20) && (1 <= (m) <= 20);
    ensures \result >= 1 && \result <= 40;
    ensures \result == ((n) == (m) ? 1 : (n) + (m) - 1);
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int m)
{
    unsigned int result;

    if (n == m)
    {
        result = 1;
        //@ assert result == 1;
    }
    else
    {
        result = n + m - 1;
        //@ assert result == n + m - 1;
    }

    return result;
}
