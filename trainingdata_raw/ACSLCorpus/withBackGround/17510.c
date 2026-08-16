/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100;
    predicate sum_in_range(integer n, integer m) = 1 <= n + m <= 200;
*/

/*@
    requires is_valid_range(n) && is_valid_range(m);
    ensures \result == n + m;
    ensures \result >= 2;
    assigns \nothing;
*/
unsigned int test_add(unsigned int n, unsigned int m)
{
    // Variable declarations at top of scope
    unsigned int result;

    //@ assert is_valid_range(n);
    //@ assert is_valid_range(m);
    //@ assert n + m >= 2;
    
    result = n + m;
    return result;
}

/*@
    lemma test_add_p:
        \forall integer n, m;
            is_valid_range(n) && is_valid_range(m) ==> sum_in_range(n, m);
*/
