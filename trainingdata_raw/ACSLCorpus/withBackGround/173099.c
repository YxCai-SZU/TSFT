#include <stddef.h>
#include <stdbool.h>

/*@ predicate is_valid_element(integer i, integer v) =
      v == i + 1 || v == 0;
*/

/*@ predicate exists_zero(int *s) =
      \exists integer j; 0 <= j < 5 && s[j] == 0;
*/

/*@ predicate all_valid(int *s) =
      \forall integer j; 0 <= j < 5 ==> is_valid_element(j, s[j]);
*/

/*@ predicate prefix_nonzero(int *s, integer i) =
      \forall integer k; 0 <= k < i ==> s[k] != 0;
*/

/*@ lemma zero_exists_in_range:
      \forall int *s;
        all_valid(s) && exists_zero(s) ==>
        \exists integer j; 0 <= j < 5 && s[j] == 0;
*/

/*@ lemma valid_element_implies_nonnegative:
      \forall integer i, v;
        0 <= i < 5 && is_valid_element(i, v) ==> v >= 0;
*/

/*@
  requires \valid(s + (0..4));
  requires all_valid(s);
  requires exists_zero(s);
  ensures 1 <= \result <= 5;
  ensures s[\result - 1] == 0;
*/
size_t func(int s[5]) {
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= 5;
      loop invariant all_valid(s);
      loop invariant exists_zero(s);
      loop invariant prefix_nonzero(s, i);
      loop assigns i;
      loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (s[i] == 0) {
            //@ assert s[i] == 0;
            return i + 1;
        }
        //@ assert s[i] != 0;
        i++;
    }
    
    return 0;
}
