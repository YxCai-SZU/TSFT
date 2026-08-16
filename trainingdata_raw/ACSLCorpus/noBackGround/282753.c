/*@
    requires (1 <= (n) <= 100);
    requires (1 <= (m) <= 100);
    ensures \result == (n <= m);
*/
_Bool func(int n, int m)
{
    // Variable declarations at scope top
    _Bool result;

    //@ assert (1 <= (n) <= 100);
    //@ assert (1 <= (m) <= 100);
    //@ assert n <= 100;
    //@ assert m >= 1;

    result = n <= m;
    return result;
}
