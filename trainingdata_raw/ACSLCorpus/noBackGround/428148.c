#include <stdbool.h>
#include <stdint.h>

/*@
  requires (1 <= (n) <= 100);
  requires \valid(numbers + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] <= 1000);
  ensures 0 <= \result <= n;
  assigns \nothing;
*/
uint32_t func(uint32_t n, int32_t *numbers) {
    uint32_t count = 0;
    uint32_t index = 0;
    bool min_exists = false;
    uint32_t min_val = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= count <= index;
      loop invariant index > 0 ==> (\forall integer i; 0 <= i < (index) ==> 1 <= (numbers)[i] <= 1000);
      loop invariant (1 <= (n) <= 100);
      loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] <= 1000);
      loop invariant (0 <= (count) <= (index) && (index) <= (n));
      loop assigns index, count, min_exists, min_val;
      loop variant n - index;
    */
    while (index < n) {
        uint32_t x = numbers[index];
        
        if (!min_exists || x <= min_val) {
            min_exists = true;
            min_val = x;
            count = count + 1;
        }
        
        index = index + 1;
    }
    
    return count;
}
