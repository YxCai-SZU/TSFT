#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
  requires (1 <= (n) <= 100);
  requires n == len;
  requires \valid_read(numbers + (0 .. len-1));
  requires (\forall integer i; 0 <= i < (len) ==> (1 <= ((numbers)[i]) <= 100));
  ensures \result >= 0 || \result == -1;
*/
int32_t func(uint32_t n, int32_t* numbers, size_t len) {
    uint32_t min = 100;
    uint32_t i = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= len;
      loop invariant index > 0 ==> \forall integer j; 0 <= j < index ==> (1 <= (numbers[j]) <= 100);
      loop invariant \forall integer k; 0 <= k < len ==> (1 <= (numbers[k]) <= 100);
      loop invariant (1 <= (n) <= 100);
      loop invariant len == n;
      loop invariant i >= 0;
      loop invariant i <= index;
      loop invariant 1 <= min <= 100;
      loop invariant index <= len;
      loop assigns min, i, index;
    */
    while (index < len) {
        uint32_t ai = (uint32_t)numbers[index];
        //@ assert (1 <= (ai) <= 100);
        if (ai < min) {
            min = ai;
            i++;
        }
        index++;
    }
    
    if (i == n) {
        return -1;
    } else {
        return (int32_t)i;
    }
}
