/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 && 0 <= m <= n;
*/

/*@
    requires valid_params(n, m);
    ensures \result == (n == m);
*/
_Bool func(unsigned int n, unsigned int m) {
    // Variable declarations at scope top
    unsigned int i;
    _Bool result;
    
    // Simulate sleep function loop
    i = 0;
    /*@
        loop invariant 0 <= i <= 100000000;
        loop invariant valid_params(n, m);
        loop assigns i;
    */
    while (i < 100000000) {
        i++;
    }
    
    // Main logic with verification properties
    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= m && m <= n;
    //@ assert n == m || n != m;
    
    result = (n == m);
    return result;
}
