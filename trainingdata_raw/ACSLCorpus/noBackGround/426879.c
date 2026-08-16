#include <stddef.h>
#include <stdbool.h>

/*@
  requires \valid(x + (0 .. 4));
  requires (\exists integer i; 0 <= i < (5) && (x)[i] == 0);
  ensures 1 <= \result <= 5;
  ensures x[\result - 1] == 0;
  assigns \nothing;
*/
int func(int *x) {
    int index = 0;
    /*@
      loop invariant 0 <= index <= 5;
      loop invariant (\exists integer i; 0 <= i < (5) && (x)[i] == 0);
      loop invariant (\forall integer j; 0 <= j < (index) ==> (x)[j] != 0);
      loop assigns index;
      loop variant 5 - index;
    */
    while (index < 5) {
        //@ assert index >= 0 && index < 5;
        if (x[index] == 0) {
            return index + 1;
        }
        index += 1;
    }
    //@ assert x[0] == 0;
    return 1;
}
