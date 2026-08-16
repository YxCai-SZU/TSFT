#include <stdint.h>
#include <stdbool.h>

/*@ predicate heights_valid(int len, int64_t *heights) =
    len >= 1 && len <= 100000 &&
    \forall integer i; 0 <= i < len ==> heights[i] >= 1 && heights[i] <= 500;
*/

/*@ predicate k_valid(int64_t k) =
    k >= 1 && k <= 500;
*/

/*@ predicate ans_nonzero_if_any(int64_t ans, int len, int64_t *heights, int64_t k) =
    \forall integer i; 0 <= i < len ==> (heights[i] >= k ==> ans > 0);
*/

/*@
    requires \valid(heights + (0..len-1));
    requires heights_valid(len, heights);
    requires k_valid(k);
    ensures \result >= 0 && \result <= len;
    ensures ans_nonzero_if_any(\result, len, heights, k);
*/
int64_t func(int64_t k, int64_t *heights, int len) {
    int64_t ans = 0;
    int index = 0;
    
    /*@
        loop invariant 0 <= index <= len;
        loop invariant 0 <= ans <= index;
        loop invariant index > 0 ==> \forall integer i; 0 <= i < index ==> (heights[i] >= k ==> ans > 0);
        loop assigns ans, index;
        loop variant len - index;
    */
    while (index < len) {
        int64_t h = heights[index];
        //@ assert h >= 1 && h <= 500;
        if (h >= k) {
            ans += 1;
            //@ assert ans > 0;
        }
        index += 1;
    }
    return ans;
}
