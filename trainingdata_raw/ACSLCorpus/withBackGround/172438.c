/*@
    predicate bounds(integer n, integer m, integer k) =
        1 <= n <= 1000 && 1 <= m <= 1000 && 0 <= k <= n * m;
    
    logic integer total_pairs_formula(integer n, integer m, integer i) =
        n * m - i;
*/

/*@
    requires bounds(n, m, k);
    ensures \result == (n * m >= k);
*/
int func(int n, int m, int k) {
    int total_pairs;
    int i;
    
    //@ assert n * m <= 1000000;
    
    total_pairs = n * m;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= k;
        loop invariant total_pairs == total_pairs_formula(n, m, i);
        loop invariant total_pairs >= 0;
        loop invariant total_pairs <= n * m;
        loop assigns total_pairs, i;
        loop variant k - i;
    */
    while (i < k) {
        //@ assert total_pairs == n * m - i;
        total_pairs -= 1;
        i += 1;
        //@ assert total_pairs == n * m - i;
    }
    
    //@ assert total_pairs == n * m - k;
    return total_pairs >= 0;
}
