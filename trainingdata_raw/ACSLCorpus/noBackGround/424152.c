#include <stdint.h>
#include <stdbool.h>

/*@
  requires n >= 1 && n <= 200000;
  requires \valid(a+(0..n-1));
  requires ((n) >= 1 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] <= 1000000000);
  assigns \nothing;
  ensures \result >= 0 || \result == -1;
  ensures \result >= 0 ==> \result <= 1000000000;
*/
int64_t func(uint32_t n, int64_t* a) {
    uint64_t before = 0;
    uint32_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant index <= n;
      loop invariant \forall integer i; 0 <= i < index ==> a[i] <= 1000000000;
      loop invariant n >= 1 && n <= 200000;
      loop assigns before, index;
      loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        if (before > (uint64_t)a[index]) {
            before = (uint64_t)a[index];
        }
        index++;
        //@ assert index <= n;
    }
    return 0;
}
