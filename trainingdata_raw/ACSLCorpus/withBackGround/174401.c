/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer square(integer n) = n * n;
    
    lemma square_bounds: \forall integer n; is_valid_n(n) ==> square(n) <= 10000;
*/

/*@
    requires is_valid_n(n);
    ensures \result == square(n);
    assigns \nothing;
*/
unsigned int func(unsigned int n)
{
    // Variable declarations at top of scope
    unsigned int result;
    
    //@ assert n <= 100;
    
    //@ assert n * n <= 10000;
    
    result = n * n;
    
    return result;
}
