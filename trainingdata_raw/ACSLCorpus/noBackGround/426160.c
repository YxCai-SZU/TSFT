#include <stdbool.h>
#include <stdint.h>

/*@
  requires 1 <= n <= 200000;
  requires \valid(a + (0..n-1));
  requires ((n) >= 1 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000000);
  assigns \nothing;
  ensures \result >= -1;
  ensures \result <= n;
*/
int32_t func(uint32_t n, int64_t *a) {
    int32_t count = 0;
    uint32_t index = 0;
    int32_t result;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant ((count) >= -1 && (count) <= (index) && (index) <= (n));
      loop invariant ((n) >= 1 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000000);
      loop invariant index > 0 ==> 
        \forall integer k; 0 <= k < index ==> 1 <= a[k] <= 1000000;
      loop assigns count, index;
      loop variant n - index;
    */
    while (index < n) {
        int64_t i = a[index];
        //@ assert 1 <= i <= 1000000;
        
        if ((i & 1) == 0) {
            count = count + 1;
        }
        //@ assert ((count) >= -1 && (count) <= (index + 1) && (index + 1) <= (n));
        
        index = index + 1;
    }
    
    if (count == 0) {
        result = -1;
    } else {
        result = count;
    }
    
    //@ assert result >= -1;
    //@ assert result <= n;
    return result;
}
