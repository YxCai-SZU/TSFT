#include <stdbool.h>

/*@ predicate exists_zero(long long *x) =
      x[0] == 0 || x[1] == 0 || x[2] == 0 || x[3] == 0 || x[4] == 0;
*/

/*@ lemma zero_exists_invariant:
      \forall long long *x; exists_zero(x) ==>
      \exists integer k; 0 <= k < 5 && x[k] == 0;
*/

/*@
  requires \valid(x + (0..4));
  requires exists_zero(x);
  ensures 1 <= \result <= 5;
  ensures x[\result - 1] == 0;
*/
int func(long long *x) {
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= 5;
      loop invariant \forall integer j; 0 <= j < i ==> x[j] != 0;
      loop assigns i;
    */
    while (i < 5) {
        //@ assert i >= 0 && i < 5;
        if (x[i] == 0) {
            //@ assert x[i] == 0;
            return i + 1;
        }
        i++;
    }
    
    // This point should be unreachable due to preconditions
    //@ assert false;
    return -1;
}
