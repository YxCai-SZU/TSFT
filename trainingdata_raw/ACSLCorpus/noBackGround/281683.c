#include <stddef.h>
#include <stdint.h>

/*@
  requires \valid(x + (0..4));
  requires \forall integer j; 0 <= j < 5 ==> ((x[j]) == (j) + 1 || (x[j]) == 0);
  requires (\exists integer j; 0 <= j < (5) && \at((x)[j], Here) == 0);
  ensures \result > 0 && \result < 6;
  ensures x[\result - 1] == 0;
*/
size_t func(int64_t x[5])
{
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= 5;
      loop invariant \forall integer j; 0 <= j < 5 ==> ((x[j]) == (j) + 1 || (x[j]) == 0);
      loop invariant (\exists integer j; 0 <= j < (5) && \at((x)[j], Here) == 0);
      loop invariant (\forall integer k; 0 <= k < (i) ==> \at((x)[k], Here) != 0);
      loop assigns i;
    */
    while (i < 5) {
        //@ assert (\forall integer k; 0 <= k < (i) ==> \at((x)[k], Here) != 0);
        if (x[i] == 0) {
            break;
        }
        i += 1;
    }
    
    //@ assert x[i] == 0;
    return i + 1;
}
