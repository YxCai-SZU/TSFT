/*@
    requires 1 <= n <= 100;
    ensures \result == (n > 1);
    assigns \nothing;
*/
_Bool func(unsigned int n)
{
    _Bool result;
    //@ assert 1 <= n <= 100;
    if (n > 1)
    {
        //@ assert n > 1;
        result = 1;
    }
    else
    {
        //@ assert n == 1;
        result = 0;
    }
    //@ assert result == (n > 1);
    return result;
}

/*@
    requires 1 <= m <= 100;
    ensures \result == (m > 1);
    assigns \nothing;
*/
_Bool func2(unsigned int m)
{
    _Bool result;
    //@ assert 1 <= m <= 100;
    if (m > 1)
    {
        //@ assert m > 1;
        result = 1;
    }
    else
    {
        //@ assert m == 1;
        result = 0;
    }
    //@ assert result == (m > 1);
    return result;
}
