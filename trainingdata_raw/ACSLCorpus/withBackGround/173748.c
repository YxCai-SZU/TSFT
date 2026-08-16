#include <stdbool.h>

/*@
    predicate valid_array(int *a, integer m) =
        \forall integer j; 0 <= j < m ==> 1 <= a[j] <= 1000;

    predicate loop_invariant(int *a, integer m, integer i, integer c, integer n) =
        0 <= i <= m &&
        0 <= c <= i &&
        valid_array(a, m) &&
        1 <= n <= 100 &&
        0 <= m <= n &&
        c <= i &&
        i <= m;

    lemma loop_decreases: \forall integer m, i; i < m ==> m - i > 0;
*/

/*@
    requires 1 <= n <= 100;
    requires 0 <= m <= n;
    requires \valid(a + (0..m-1));
    requires valid_array(a, m);
    ensures \result >= 0;
    ensures \result <= n;
*/
int func(int n, int m, int *a) {
    int c = 0;
    int i = 0;
    
    /*@
        loop invariant loop_invariant(a, m, i, c, n);
        loop assigns i, c;
        loop variant m - i;
    */
    while (i < m) {
        //@ assert 0 <= i < m;
        if (a[i] & 1 == 1) {
            c += 1;
        }
        i += 1;
    }
    
    int ans;
    if (c & 1 == 1) {
        ans = n - c;
    } else {
        ans = c;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= n;
    return ans;
}
