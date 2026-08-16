/*@
    requires (1 <= (x) && (x) <= 100);
    ensures \result == (3 * (x) * (x));
    assigns \nothing;
*/
long func(long x)
{
    // Variable declarations at scope top
    long res;

    //@ assert (1 <= (x) && (x) <= 100);
    //@ assert 3 * x >= 3 * 1;
    //@ assert 3 * x <= 3 * 100;
    //@ assert (3 * (x) * (x)) >= 3 * 1 * 1;
    //@ assert (3 * (x) * (x)) <= 3 * 100 * 100;

    res = 3 * x * x;
    return res;
}
