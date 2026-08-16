#include <stddef.h>
#include <stdbool.h>

/*@
  requires \valid(v + (0..6));
  requires (\exists integer j; 0 <= j < (7) && (v)[j] == 0);
  ensures \result == 0 || (1 <= \result <= 7 && v[\result - 1] == 0);
  assigns \nothing;
*/
size_t func(size_t *v) {
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= 7;
        loop invariant (\forall integer k; 0 <= k < (i) ==> (v)[k] != 0);
        loop assigns i;
        loop variant 7 - i;
    */
    while (i < 7) {
        if (v[i] == 0) {
            //@ assert v[i] == 0;
            return i + 1;
        }
        i += 1;
    }
    return 0;
}
