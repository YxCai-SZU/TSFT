#include <stddef.h>
#include <stdint.h>

/*@
  requires ((k) >= 1 &&
    (n) >= 1 &&
    (n) <= 100000 &&
    \valid((h) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (1 <= (h)[i] && (h)[i] <= 500));
  assigns \nothing;
  ensures \result >= 0 && \result <= (int32_t)n;
*/
int32_t func(size_t k, size_t n, size_t *h) {
    int32_t ans = 0;
    size_t index = 0;
    
    //@ assert ((k) >= 1 &&     (n) >= 1 &&     (n) <= 100000 &&     \valid((h) + (0 .. (n)-1)) &&     \forall integer i; 0 <= i < (n) ==> (1 <= (h)[i] && (h)[i] <= 500));
    //@ assert ((index) <= (n) &&     (ans) >= 0 &&     (ans) <= (int32_t)(index) &&     \valid((h) + (0 .. (n)-1)) &&     \forall integer i; 0 <= i < (n) ==> (1 <= (h)[i] && (h)[i] <= 500));
    
    /*@ loop invariant ((index) <= (n) &&
    (ans) >= 0 &&
    (ans) <= (int32_t)(index) &&
    \valid((h) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (1 <= (h)[i] && (h)[i] <= 500));
        loop assigns index, ans;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert ((index) <= (n) &&     (ans) >= 0 &&     (ans) <= (int32_t)(index) &&     \valid((h) + (0 .. (n)-1)) &&     \forall integer i; 0 <= i < (n) ==> (1 <= (h)[i] && (h)[i] <= 500));
        
        if (h[index] >= k) {
            ans += 1;
        }
        
        index += 1;
        //@ assert ans >= 0 && ans <= (int32_t)index;
    }
    
    //@ assert index == n;
    //@ assert ans >= 0 && ans <= (int32_t)n;
    return ans;
}
