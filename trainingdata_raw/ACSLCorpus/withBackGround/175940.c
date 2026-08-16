/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= 100;
    
    logic integer product(integer n, integer m) = n * m;
    
    lemma product_bounds:
        \forall integer n, m;
        valid_range(n, m) ==> 1 <= product(n, m) <= 10000;
    
    lemma max_product:
        \forall integer n, m;
        valid_range(n, m) ==> product(n, m) <= 100 * 100;
*/

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures \result == n * m;
    assigns \nothing;
*/
int func(int n, int m)
{
    // Variable declarations at scope top
    int result;
    
    //@ assert valid_range(n, m);
    
    //@ assert 1 <= n * m && n * m <= 10000;
    
    //@ assert n * m <= 100 * 100;
    
    result = n * m;
    
    //@ assert result == n * m;
    
    return result;
}
