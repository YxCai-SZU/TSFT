/*@
    predicate valid_params(integer n, integer m) =
        1 <= n && n <= 100 &&
        1 <= m && m <= 100;

    logic integer product(integer n, integer m) = n * m;

    lemma product_bound: \forall integer n, m;
        valid_params(n, m) ==> product(n, m) <= 10000;
*/

/*@
    requires valid_params(n, m);
    ensures \result == product(n, m);
    assigns \nothing;
*/
unsigned long func(unsigned long n, unsigned long m)
{
    // Variable declarations at scope top
    unsigned long result;

    //@ assert valid_params(n, m);
    //@ assert product(n, m) <= 10000;

    result = n * m;
    //@ assert result == product(n, m);
    return result;
}
