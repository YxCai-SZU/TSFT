#include <stddef.h>
#include <stdbool.h>

/*@
  requires \valid(x + (0..4));
  requires \forall integer i; 0 <= i < 5 ==> ((x[i]) == 0 || (x[i]) == 1);
  ensures 0 <= \result <= 1;
  assigns \nothing;
*/
size_t func(size_t x[5]) {
    size_t c = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= 5;
      loop invariant 0 <= c <= i;
      loop invariant \forall integer j; 0 <= j < 5 ==> ((x[j]) == 0 || (x[j]) == 1);
      loop invariant \forall integer k; 0 <= k < i ==> (x[k] == 0 ==> c > 0);
      loop assigns c, i;
      loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (x[i] == 0) {
            c += 1;
        }
        i += 1;
    }
    
    //@ assert 0 <= c <= 5;
    if (c > 2) {
        //@ assert 0 <= 0 <= 1;
        return 0;
    } else {
        //@ assert 0 <= 1 <= 1;
        return 1;
    }
}
