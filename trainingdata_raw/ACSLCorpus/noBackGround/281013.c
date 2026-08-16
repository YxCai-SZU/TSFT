/*@
    requires (1 <= (n) <= 1000000);
    ensures \result == (((n) - 1) / 2 + 1);
    ensures 1 <= \result <= n;
*/
unsigned int func(unsigned int n)
{
    unsigned int result;
    //@ assert (1 <= (n) <= 1000000);
    //@ assert (((n) - 1) / 2 + 1) == (((n) - 1) / 2 + 1);
    //@ assert 1 <= (((n) - 1) / 2 + 1) <= n;
    //@ assert (((n) - 1) / 2 + 1) <= n;
    result = (n - 1) / 2 + 1;
    return result;
}
