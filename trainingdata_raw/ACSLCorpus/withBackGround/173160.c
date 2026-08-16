#include <stdbool.h>
#include <stddef.h>

/*@ predicate heights_in_range(int *heights, integer n) =
      \forall integer i; 0 <= i < n ==> 1 <= heights[i] <= 500;
*/

/*@ predicate loop_invariant(int *heights, integer n, integer k, 
                             integer a, integer index) =
      0 <= a <= n &&
      index == a &&
      \forall integer i; 0 <= i < a ==> 1 <= heights[i] <= 500;
*/

/*@ lemma loop_decreases: 
      \forall integer n, integer a; a < n ==> n - a > 0;
*/

/*@ requires 1 <= n;
    requires 1 <= k;
    requires \valid(heights + (0 .. n-1));
    requires heights_in_range(heights, n);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(int n, int k, int *heights) {
    int cnt = 0;
    int a = 0;
    size_t index = 0;
    
    /*@ loop invariant loop_invariant(heights, n, k, a, index);
        loop invariant heights_in_range(heights, n);
        loop invariant 0 <= cnt <= a;
        loop assigns cnt, a, index;
        loop variant n - a;
    */
    while (a < n) {
        int hi = heights[index];
        
        //@ assert 1 <= hi <= 500;
        
        if (hi >= k) {
            cnt += 1;
        }
        
        a += 1;
        index += 1;
    }
    
    return cnt;
}
