#include <stdbool.h>
#include <stdint.h>

/*@
  requires (1 <= (n) && (n) <= 100);
  requires \valid_read(numbers + (0 .. n-1));
  requires \forall integer i; 0 <= i < n ==> (1 <= (numbers[i]) && (numbers[i]) <= 1000);
  ensures 0 <= \result <= n;
*/
uint32_t func(uint32_t n, const uint32_t numbers[]) {
    uint32_t count = 0;
    uint32_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= count <= index;
      loop invariant \forall integer i; 0 <= i < n ==> (1 <= (numbers[i]) && (numbers[i]) <= 1000);
      loop invariant (1 <= (n) && (n) <= 100);
      loop assigns count, index;
    */
    while (index < n) {
        uint32_t a = numbers[index];
        
        if ((a & 1U) == 1U) {
            //@ assert (a & 1U) == 1U;
            if ((a & (a - 1U)) == 0U) {
                //@ assert (a & (a - 1U)) == 0U;
                count += 1U;
            }
        }
        index += 1U;
    }
    return count;
}
