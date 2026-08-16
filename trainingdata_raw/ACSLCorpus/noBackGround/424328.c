#include <stdbool.h>
#include <stdint.h>

/*@
  requires n <= 100;
  requires \valid(numbers + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 1000));
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
uint32_t func(uint32_t n, int32_t *numbers) {
    uint32_t count = 0;
    uint32_t i = 0;
    
    //@ assert n <= 100;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= count <= i;
      loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 1000));
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n) {
        int32_t a = numbers[i];
        
        //@ assert (1 <= (a) <= 1000);
        
        if (a % 2 == 0) {
            if (a % 3 == 0 || a % 5 == 0) {
                count = count + 1;
            }
        }
        
        i = i + 1;
    }
    
    //@ assert (0 <= (i) <= (n) &&       (count) >= 0 &&       (count) <= (i));
    return count;
}
