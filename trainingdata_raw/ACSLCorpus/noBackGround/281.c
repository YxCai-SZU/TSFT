/*@
    requires (1 <= (d) <= 10000 &&
        1 <= (t) <= 10000 &&
        1 <= (s) <= 10000);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
int func(long long d, long long t, long long s)
{
    // Variable declarations at scope top
    long long product;
    int result;

    //@ assert 1 <= t && t <= 10000;
    //@ assert 1 <= s && s <= 10000;
    //@ assert t * s <= 10000 * 10000;

    product = t * s;
    result = (d <= product) ? 1 : 0;
    return result;
}
