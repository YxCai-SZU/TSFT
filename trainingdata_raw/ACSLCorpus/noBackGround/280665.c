#include <stdbool.h>
#include <stdint.h>

/*@
  requires n > 0;
  requires \valid(numbers + (0 .. n-1));
  requires \forall integer i; 0 <= i < n ==> numbers[i] > 0 && numbers[i] <= 1000;
  assigns \nothing;
  ensures \result >= 0 && \result <= n;
*/
uint32_t func(uint32_t n, uint32_t numbers[]) {
    uint32_t count = 0;
    uint32_t index = 0;
    
    /*@
      loop invariant ((index) >= 0 && (index) <= (n) &&
      (count) >= 0 && (count) <= (index) &&
      (((n)) > 0 &&
      \valid(((numbers)) + (0 .. ((n))-1)) &&
      \forall integer i; 0 <= i < ((n)) ==> ((numbers))[i] > 0 && ((numbers))[i] <= 1000));
      loop invariant index <= n;
      loop invariant count <= index;
      loop assigns index, count;
      loop variant n - index;
    */
    while (index < n) {
        uint32_t num = numbers[index];
        
        //@ assert index % 2 == 0 ==> (num % 2 == 1) ==> count + 1 <= index + 1;
        
        if (index % 2 == 0 && num % 2 == 1) {
            count += 1;
        }
        index += 1;
    }
    
    //@ assert count >= 0 && count <= n;
    return count;
}
