#include <stdbool.h>
#include <stdint.h>

/*@
  requires n > 0 && n <= 50;
  requires \valid(a + (0 .. n-1));
  requires \forall integer j; 0 <= j < n ==> 0 <= a[j] <= 100;
  ensures \result >= 0 && \result <= n;
  assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t* a) {
    uint64_t count = 0;
    uint64_t i = 0;
    
    /*@ loop invariant ((i) >= 0 && (i) <= (n) &&
      (count) >= 0 && (count) <= (i) &&
      (((n)) > 0 && ((n)) <= 50 &&
      \valid(((a)) + (0 .. ((n))-1)) &&
      \forall integer j; 0 <= j < ((n)) ==> 0 <= ((a))[j] <= 100));
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert ((i) >= 0 && (i) <= (n) &&       (count) >= 0 && (count) <= (i) &&       (((n)) > 0 && ((n)) <= 50 &&       \valid(((a)) + (0 .. ((n))-1)) &&       \forall integer j; 0 <= j < ((n)) ==> 0 <= ((a))[j] <= 100));
        
        if ((a[i] & 1) == 0) {
            count = count + 1;
        }
        
        i = i + 1;
    }
    
    //@ assert i == n;
    return count;
}
