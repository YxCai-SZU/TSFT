#include <stdbool.h>
#include <stddef.h>

/*@
  requires (1 <= (x) <= 100);
  requires \valid(numbers + (0..4));
  requires (\forall integer i; 0 <= i < (5) ==> (0 <= ((numbers)[i]) <= 5));
  requires (\exists integer i; 0 <= i < (5) && (numbers)[i] == (x));
  ensures \result >= 0 && \result <= 5;
  ensures numbers[\result - 1] == x;
*/
int func(int x, int *numbers) {
    size_t index;
    index = 0;
    
    /*@
      loop invariant 0 <= index <= 5;
      loop invariant (\forall integer i; 0 <= i < (5) ==> (0 <= ((numbers)[i]) <= 5));
      loop invariant (\exists integer i; 0 <= i < (5) && (numbers)[i] == (x));
      loop invariant (\forall integer k; 0 <= k < (index) ==> (numbers)[k] != (x));
      loop invariant (1 <= (x) <= 100);
      loop assigns index;
    */
    while (index < 5) {
        //@ assert (\forall integer i; 0 <= i < (5) ==> (0 <= ((numbers)[i]) <= 5));
        if (numbers[index] == x) {
            //@ assert numbers[index] == x;
            return (int)(index + 1);
        }
        //@ assert numbers[index] != x;
        index += 1;
    }
    return -1;
}
