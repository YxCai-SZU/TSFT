#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_params(integer n, integer k) =
      n >= 1 && n <= 100000 &&
      k >= 1 && k <= 500;
*/

/*@ predicate valid_heights(int *heights, integer n) =
      \forall integer i; 0 <= i < n ==> heights[i] >= 1 && heights[i] <= 500;
*/

/*@ lemma heights_bounds:
      \forall int *heights, integer n;
      valid_heights(heights, n) ==> 
      \forall integer x; 0 <= x < n ==> heights[x] >= 1 && heights[x] <= 500;
*/

/*@ logic integer count_ge_k(int *heights, integer n, integer k, integer idx) =
      idx <= 0 ? 0 :
      count_ge_k(heights, n, k, idx-1) + (heights[idx-1] >= k ? 1 : 0);
*/

/*@ requires valid_params(n, k);
    requires \valid(heights + (0..n-1));
    requires valid_heights(heights, n);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result <= n;
*/
int func(int n, int k, int *heights) {
    int cnt = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant cnt >= 0;
        loop invariant cnt <= i;
        loop invariant valid_heights(heights, n);
        loop invariant valid_params(n, k);
        loop assigns i, cnt;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert heights[i] >= 1 && heights[i] <= 500;
        if (heights[i] >= k) {
            cnt++;
        }
        i++;
    }
    
    if (cnt == n) {
        return cnt;
    } else {
        int min = cnt;
        int j = 0;
        
        /*@ loop invariant 0 <= j <= cnt;
            loop invariant min >= 0;
            loop invariant min <= n;
            loop invariant valid_heights(heights, n);
            loop invariant valid_params(n, k);
            loop assigns j, min;
            loop variant cnt - j;
        */
        while (j < cnt) {
            //@ assert cnt - j >= 0;
            if (cnt - j > n - 1) {
                j++;
                continue;
            }
            if (cnt - j == n - 1) {
                if (cnt - j < min) {
                    min = cnt - j;
                }
                j++;
                continue;
            }
            int diff = n - 1 - (cnt - j);
            //@ assert diff >= 0;
            if (diff < k) {
                if (cnt - j < min) {
                    min = cnt - j;
                }
            }
            j++;
        }
        return (min >= 0) ? min : -1;
    }
}
