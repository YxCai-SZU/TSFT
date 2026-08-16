/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n));
    ensures \result == (n == m);
*/
_Bool func(long n, long m) {
    // Variable declarations at scope top
    _Bool result;
    
    //@ assert n == m ==> n == m;
    
    result = (n == m);
    return result;
}
