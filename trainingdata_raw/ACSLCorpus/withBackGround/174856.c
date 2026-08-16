#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int *arr, integer n) =
      n > 0 && n <= 20 &&
      \forall integer i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= 100;
*/

/*@ predicate loop_invariant(int *h, integer n, integer i, integer ans, integer acc) =
      i <= n &&
      ans >= 0 &&
      ans <= i &&
      acc >= 0 &&
      \forall integer j; 0 <= j < n ==> h[j] >= 1 && h[j] <= 100;
*/

/*@ lemma ans_bounds: \forall integer n, ans; 0 <= ans <= n ==> ans >= 0 && ans <= n; */

/*@ requires n > 0 && n <= 20;
    requires \valid(h + (0 .. n-1));
    requires valid_array(h, n);
    ensures \result >= 0 && \result <= n;
*/
int func(int n, int *h) {
    int ans = 0;
    int acc = 0;
    size_t i = 0;
    
    /*@ loop invariant loop_invariant(h, n, i, ans, acc);
        loop invariant i <= n;
        loop assigns ans, acc, i;
        loop variant n - i;
    */
    while (i < (size_t)n) {
        int h_i = h[i];
        
        //@ assert h_i >= 1 && h_i <= 100;
        
        if (acc >= h_i) {
            ans += 1;
            acc = 0;
        } else {
            acc += h_i;
        }
        
        //@ assert ans >= 0;
        //@ assert ans <= i + 1;
        //@ assert acc >= 0;
        
        i += 1;
    }
    
    //@ assert ans >= 0 && ans <= n;
    return ans;
}

int main() {
    return 0;
}
