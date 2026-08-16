#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(v + (0 .. 4));
  requires \forall integer i; 0 <= i < 5 ==> (v[i] == i+1 || v[i] == 0);
  requires \exists integer i; 0 <= i < 5 && v[i] == 0;
  ensures 1 <= \result <= 5;
  ensures v[\result - 1] == 0;
*/
long func(long v[5]) {
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= 5;
      loop invariant (\exists integer k; 0 <= k < (5) && (v)[k] == 0);
      loop invariant (\forall integer j; 0 <= j < (i) ==> (v)[j] != 0);
      loop invariant (\forall integer k; 0 <= k < (5) ==> ((v)[k] == k+1 || (v)[k] == 0));
      loop assigns i;
      loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (v[i] == 0) {
            //@ assert v[i] == 0;
            return (long)(i + 1);
        }
        //@ assert v[i] != 0;
        i += 1;
    }
    return -1;
}
