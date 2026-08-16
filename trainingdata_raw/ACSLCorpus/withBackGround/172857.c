#include <limits.h>

/*@ predicate valid_h(integer n, int *h) =
      n >= 1 && n <= 20 &&
      \valid(h + (0..n-1)) &&
      \forall integer k; 0 <= k < n ==> h[k] >= 1 && h[k] <= 20;
*/

/*@ predicate valid_w(integer m, int *w) =
      m >= 1 && m <= 20 &&
      \valid(w + (0..m-1)) &&
      \forall integer k; 0 <= k < m ==> w[k] >= 1 && w[k] <= 20;
*/

/*@ lemma bounds_preserved:
      \forall integer n, m, int *h, int *w;
      valid_h(n, h) && valid_w(m, w) ==> n >= 1 && n <= 20 && m >= 1 && m <= 20;
*/

/*@ logic integer min_sum(integer n, integer m, int *h, int *w) =
      \min(0, n-1, (\lambda integer i; 
        \min(0, m-1, (\lambda integer j; h[i] + w[j]))));
*/

/*@ requires valid_h(n, h) && valid_w(m, w);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int m, int *h, int *w) {
    int ans = INT_MAX;
    int a = 0;
    int i = 0;
    
    //@ assert ans >= 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant ans >= 0;
        loop invariant a >= 0 && a <= 20;
        loop invariant valid_h(n, h);
        loop invariant valid_w(m, w);
        loop assigns ans, a, i;
        loop variant n - i;
    */
    while (i < n) {
        a = h[i];
        int j = 0;
        
        /*@ loop invariant 0 <= j <= m;
            loop invariant ans >= 0;
            loop invariant a >= 0 && a <= 20;
            loop invariant valid_h(n, h);
            loop invariant valid_w(m, w);
            loop assigns ans, j;
            loop variant m - j;
        */
        while (j < m) {
            int tmp = a + w[j];
            if (tmp < ans) {
                ans = tmp;
            }
            //@ assert ans >= 0;
            j++;
        }
        i++;
    }
    return ans;
}
