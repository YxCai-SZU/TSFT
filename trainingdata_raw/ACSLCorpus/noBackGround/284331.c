#include <stdbool.h>

/*@
  requires \valid(numbers + (0..4));
  requires \forall integer i; 0 <= i < 5 ==> ((numbers[i]) == 0 || (numbers[i]) == 1);
  ensures \result >= 0 && \result <= 5;
  assigns \nothing;
*/
int func(int numbers[5]) {
    int x = 0;
    int index = 0;
    
    /*@
      loop invariant 0 <= index <= 5;
      loop invariant x >= 0;
      loop invariant x <= index;
      loop invariant \forall integer i; 0 <= i < index ==> ((numbers[i]) == 0 || (numbers[i]) == 1);
      loop assigns x, index;
      loop variant 5 - index;
    */
    while (index < 5) {
        int i = numbers[index];
        //@ assert ((i) == 0 || (i) == 1);
        if (i == 0) {
            x += 1;
        }
        index += 1;
    }
    return x;
}
