#include <stdbool.h>
#include <stdint.h>

/*@ predicate distinct_elements(uint32_t* arr, integer len) =
      \forall integer i, j; 0 <= i < j < len ==> arr[i] != arr[j];
*/

/*@
  requires 2 <= n <= 200;
  requires 1 <= k <= n-1;
  requires \valid(a + (0..n-1));
  requires distinct_elements(a, n);
  assigns \nothing;
  ensures \result < n;
*/
uint32_t func(uint32_t n, uint32_t k, uint32_t* a) {
    uint32_t res = 0;
    uint32_t i = 1;
    
    /*@
      loop invariant 1 <= i <= n;
      loop invariant res < n;
      loop assigns res, i;
      loop variant n - i;
    */
    while (i < n) {
        if (a[i] < a[i - 1]) {
            res = n - k;
        } else {
            res = k - 1;
        }
        i++;
        
        //@ assert res < n;
    }
    
    //@ assert res < n;
    return res;
}
