/*@
    predicate valid_range(integer n, integer m) =
        2 <= n <= 100 && 2 <= m <= 100;

    logic integer product(integer n, integer m) = n * m;
    logic integer sum_minus_one(integer n, integer m) = n + m - 1;
    logic integer final_result(integer n, integer m) = product(n, m) - sum_minus_one(n, m);

    lemma product_bound: \forall integer n, m; valid_range(n, m) ==> product(n, m) <= 10000;
    lemma sum_bound: \forall integer n, m; valid_range(n, m) ==> sum_minus_one(n, m) <= 199;
    lemma no_underflow: \forall integer n, m; valid_range(n, m) ==> product(n, m) >= sum_minus_one(n, m);
*/

/*@
    requires 2 <= n <= 100 && 2 <= m <= 100;
    ensures \result == (n * m) - (n + m - 1);
*/
int func(unsigned int n, unsigned int m)
{
    // Variable declarations at scope top
    unsigned int n_m;
    unsigned int n_p_m;
    int result;

    //@ assert n * m <= 10000;
    //@ assert n + m - 1 <= 199;
    //@ assert n * m >= n + m - 1;

    n_m = n * m;
    n_p_m = n + m - 1;
    result = (int)(n_m - n_p_m);
    
    return result;
}
