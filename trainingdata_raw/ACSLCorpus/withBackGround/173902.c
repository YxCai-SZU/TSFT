/*@
    predicate is_equal(integer n, integer m) = n == m;
*/

/*@
    requires 1 <= n && n <= 100;
    requires 0 <= m && m <= n;
    ensures \result == (n == m);
    assigns \nothing;
*/
_Bool func(unsigned int n, unsigned int m) {
    // Variable declarations at the top of scope
    _Bool result;
    
    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= m && m <= n;
    
    result = (n == m);
    
    //@ assert result == (n == m);
    return result;
}

/*@
    lemma func_postcondition:
        \forall integer n, integer m, _Bool result;
        1 <= n && n <= 100 && 0 <= m && m <= n && result == (n == m) ==>
        result == (n == m);
*/

/*@
    lemma func_test1:
        is_equal(5, 5);
*/

/*@
    lemma func_test2:
        !is_equal(5, 3);
*/
