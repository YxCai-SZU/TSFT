/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 && 0 <= m <= n;
    
    logic integer diff(integer n, integer m) = n - m;
    
    lemma diff_nonnegative:
        \forall integer n, m; valid_params(n, m) ==> diff(n, m) >= 0;
*/

/*@
    requires valid_params(n, m);
    ensures \result == diff(n, m);
    assigns \nothing;
*/
int func(int n, int m) {
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= m;
        loop invariant valid_params(n, m);
        loop assigns i;
        loop variant m - i;
    */
    while (i < m) {
        i = i + 1;
    }
    
    //@ assert diff(n, m) >= 0;
    return n - m;
}

int main() {
    return 0;
}
