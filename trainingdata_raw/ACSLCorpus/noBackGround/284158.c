#include <stdint.h>
#include <stdbool.h>

/*@
  requires n >= 1 && n <= 100;
  requires \valid(numbers + (0 .. n-1));
  requires \forall integer i; 0 <= i < n ==> numbers[i] >= 1 && numbers[i] <= 1000;
  ensures \result >= -1;
  ensures \result <= n;
  assigns \nothing;
*/
int32_t func(uint32_t n, int32_t numbers[]) {
    int32_t count = 0;
    uint32_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= count <= index;
      loop invariant index > 0 ==> \forall integer i; 0 <= i < index ==> numbers[i] >= 1 && numbers[i] <= 1000;
      loop invariant (\valid((numbers) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (((numbers)[i]) >= 1 && ((numbers)[i]) <= 1000));
      loop assigns index, count;
      loop variant n - index;
    */
    while (index < n) {
        int32_t ai = numbers[index];
        
        //@ assert ((ai) >= 1 && (ai) <= 1000);
        
        if ((int32_t)index + 1 < ai) {
            count = count + 1;
        }
        
        index = index + 1;
    }
    
    if (count == 0) {
        return -1;
    } else {
        return count;
    }
}
