/*@
    requires 1 <= n <= 0xFFFFFFFF;
    ensures \result == (n % 2 != 0);
    assigns \nothing;
*/
unsigned int is_odd(unsigned int n)
{
    //@ assert 1 <= n <= 0xFFFFFFFF;
    unsigned int ret = n % 2 != 0;
    //@ assert ret == (n % 2 != 0);
    return ret;
}

/*@
    requires 1 <= r <= 100;
    ensures \result == 3 * r * r;
    assigns \nothing;
*/
int func(int r)
{
    //@ assert 1 <= r <= 100;
    int pi = 3;
    //@ assert 3 * r * r <= 3 * 100 * 100;
    int result = pi * r * r;
    //@ assert result == 3 * r * r;
    return result;
}
