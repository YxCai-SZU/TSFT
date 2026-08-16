#include <stdbool.h>
#include <stdint.h>

/*@
  requires n >= 2 && n <= 200000;
  requires \valid(numbers + (0 .. n-1));
  requires ((n) >= 2 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 1000000);
  assigns \nothing;
  ensures \result >= 1 && \result <= n;
*/
uint32_t func(uint32_t n, uint32_t numbers[]) {
    uint32_t count;
    uint32_t i;
    uint32_t pre;
    uint32_t idx;
    uint32_t v;
    
    count = 1;
    i = 0;
    pre = numbers[0];
    idx = 1;
    
    /*@
      loop invariant 1 <= idx <= n;
      loop invariant ((count) >= 1 && (count) <= (idx));
      loop invariant ((n) >= 2 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 1000000);
      loop assigns count, pre, idx, v;
      loop variant n - idx;
    */
    while (idx < n) {
        v = numbers[idx];
        
        //@ assert v >= 1 && v <= 1000000;
        
        if (pre >= v) {
            pre = v;
            count = count + 1;
        }
        
        //@ assert ((count) >= 1 && (count) <= (idx + 1));
        idx = idx + 1;
    }
    
    //@ assert ((count) >= 1 && (count) <= (n));
    return count;
}
