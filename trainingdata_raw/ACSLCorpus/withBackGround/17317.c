#include <stdbool.h>
#include <stddef.h>

/*@ predicate exists_zero(size_t *xs, integer len) =
      \exists integer i; 0 <= i < len && xs[i] == 0;
*/

/*@ predicate all_nonzero(size_t *xs, integer start, integer end) =
      \forall integer k; start <= k < end ==> xs[k] != 0;
*/

/*@ lemma existence_lemma:
      \forall size_t *xs, integer len;
      len == 5 && exists_zero(xs, len) ==>
      \exists integer j; 0 <= j < 5 && xs[j] == 0;
*/

/*@
  requires \valid(xs + (0 .. 4));
  requires exists_zero(xs, 5);
  ensures \result > 0 && \result <= 5;
  ensures xs[\result - 1] == 0;
  assigns \nothing;
*/
size_t func(size_t *xs) {
    size_t pos = 0;
    bool found = false;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= 5;
      loop invariant i > 0 ==> (!found ==> all_nonzero(xs, 0, i));
      loop invariant found ==> all_nonzero(xs, 0, i);
      loop invariant exists_zero(xs, 5);
      loop assigns i, pos, found;
      loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (xs[i] == 0) {
            pos = i;
            found = true;
            break;
        }
        i++;
    }
    
    if (found) {
        //@ assert xs[pos] == 0;
        //@ assert 0 <= pos < 5;
        return pos + 1;
    } else {
        return 0;
    }
}
