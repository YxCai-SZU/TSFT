/*@
    requires 1 <= n <= 100;
    requires 0 <= m <= n;
    ensures \result == (n == m);
*/
_Bool func(unsigned int n, unsigned int m)
{
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= m <= n;
    return n == m;
}

/*@
    requires 1 <= n <= 100;
    requires 0 <= m <= n;
    ensures \result == (n == m);
*/
_Bool func_odd_even(unsigned int n, unsigned int m)
{
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= m <= n;
    return n == m;
}
