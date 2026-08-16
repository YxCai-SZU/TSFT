#include <limits.h>
#include <stddef.h>

/*@ predicate valid_array(int *arr, integer n) =
      n >= 1 && n <= 20 &&
      \forall integer i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= 100;
*/

/*@ predicate loop_invariant(int *h, integer n, integer idx, integer res, int cur) =
      idx >= 0 && idx <= n &&
      res >= 0 && res <= idx &&
      valid_array(h, n);
*/

/*@ lemma res_bound: \forall int *h, integer n, integer idx, integer res, int cur;
      loop_invariant(h, n, idx, res, cur) ==> res >= 0 && res <= n;
*/


int func(int n, int *h) {
    int res = 0;
    int current = INT_MIN;
    size_t index = 0;
    
    
    while (index < (size_t)n) {
        int next_h = h[index];
        if (next_h >= current) {
            res += 1;
            current = next_h;
        }
        index += 1;
    }
    
    //@ assert res >= 0 && res <= n;
    return res;
}
