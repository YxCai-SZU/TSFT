/*@
    predicate is_square(integer n, integer result) =
        result == n * n;

    lemma square_bound:
        \forall integer n; n >= 0 && n < 65536 ==> n * n <= 4294967295;
*/

/*@
    requires n < 65536;
    ensures \result == n * n;
    assigns \nothing;
*/
unsigned int find_square_num(unsigned int n)
{
    // Variable declarations at top of scope
    unsigned int result;

    //@ assert n < 65536;
    //@ assert n * n <= 4294967295;
    
    result = n * n;
    
    //@ assert result == n * n;
    return result;
}
