/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer star_num(integer n) = 6 * n * (n + 1);
    
    lemma overflow_bound: \forall integer n; valid_n(n) ==> 6 * n <= 600;
    lemma result_bound: \forall integer n; valid_n(n) ==> star_num(n) <= 600 * 101;
*/

/*@
    requires valid_n(n);
    ensures \result == star_num(n);
    assigns \nothing;
*/
unsigned int find_star_num(unsigned int n)
{
    // Variable declarations at scope top
    unsigned int result;
    
    //@ assert valid_n(n);
    //@ assert 6 * n <= 600;
    //@ assert star_num(n) <= 600 * 101;
    
    result = 6 * n * (n + 1);
    
    //@ assert result == star_num(n);
    return result;
}
