/*@
    predicate is_valid_range(integer r) = 1 <= r <= 100;
    predicate is_nonnegative(integer x) = x >= 0;
*/

/*@
    requires is_valid_range(r);
    ensures \result == 3 * r * r;
    ensures is_nonnegative(\result);
*/
long func(long r) {
    long pi_approx;
    long ans;
    
    pi_approx = 3;
    
    //@ assert pi_approx * r * r == 3 * r * r;
    //@ assert 0 <= pi_approx * r * r <= 3 * 100 * 100;
    
    ans = pi_approx * r * r;
    return ans;
}
