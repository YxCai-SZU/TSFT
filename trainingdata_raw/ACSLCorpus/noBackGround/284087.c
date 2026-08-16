#include <stddef.h>

/*@
  requires \valid(x + (0..4));
  requires x[0] == 0 || x[1] == 0 || x[2] == 0 || x[3] == 0 || x[4] == 0;
  ensures \result > 0;
  ensures \result <= 5;
  ensures x[\result - 1] == 0;
*/
size_t func(int* x) {
    size_t i = 0;
    /*@
      loop invariant 0 <= i <= 5;
      loop invariant \valid(x + (0..4));
      loop invariant (\exists integer j; 0 <= j < (5) && (x)[j] == 0);
      loop invariant (\forall integer k; 0 <= k < (i) ==> (x)[k] != 0);
      loop assigns i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (x[i] == 0) {
            return i + 1;
        }
        i++;
    }
    return 0;
}
