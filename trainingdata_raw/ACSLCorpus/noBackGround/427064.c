/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n));
    ensures \result == (n == m);
*/
_Bool func(unsigned int n, unsigned int m)
{
    // Variable declarations at top of scope
    _Bool result;

    //@ assert n == m ==> n == m;
    result = (n == m);
    return result;
}
