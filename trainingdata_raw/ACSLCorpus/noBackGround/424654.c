#include <stdbool.h>
#include <stdint.h>

/*@
  requires 1 <= n <= 100000;
  requires \valid(numbers + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> 1 <= numbers[i] <= 1000000;
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
uint32_t func(uint32_t n, const uint32_t numbers[]) {
    uint32_t i = 0;
    uint32_t count = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= count <= i;
      loop invariant \forall integer j; 0 <= j < n ==> 1 <= numbers[j] <= 1000000;
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert i < n;
        if (i & 1) {
            uint32_t a = numbers[i];
            //@ assert 1 <= a <= 1000000;
            if ((a & 1) == 0) {
                count = count + 1;
            }
        }
        i = i + 1;
    }
    return count;
}
