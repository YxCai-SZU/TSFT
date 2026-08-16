/*@
    requires 1 <= n <= 100000;
    ensures \result == 0 || \result == 1;
    ensures ((\result) == 0 || (\result) == 1);
*/
int func(unsigned int n)
{
    unsigned int a;
    int is_even;

    a = 1;
    is_even = 1;

    /*@
        loop invariant 1 <= a <= n + 1;
        loop invariant ((is_even) == 0 || (is_even) == 1);
        loop assigns a, is_even;
        loop variant n - a + 1;
    */
    while (a <= n)
    {
        //@ assert 1 <= a <= n + 1;
        if ((a & 1) == 0)
        {
            is_even = 0;
        }
        a = a + 1;
    }

    //@ assert ((is_even) == 0 || (is_even) == 1);
    if (is_even)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
