#include <stddef.h>
#include <stdbool.h>

/*@ predicate equal_at(integer i, int *list1, int *list2, integer len) =
      0 <= i < len ==> list1[i] == list2[i];
*/

/*@ predicate not_equal_at(integer i, int *list1, int *list2, integer len) =
      0 <= i < len ==> list1[i] != list2[i];
*/

/*@ lemma count_property:
      \forall integer i, integer count, int *list1, int *list2, integer len;
      (0 <= i <= len && count <= i &&
      (\forall integer k; 0 <= k < i ==> (list1[k] == list2[k] ==> count >= 1)) &&
      (\forall integer k; 0 <= k < i ==> (list1[k] != list2[k] ==> count >= 0)))
      ==> count <= len;
*/

/*@
  requires \valid(list1 + (0..len-1));
  requires \valid(list2 + (0..len-1));
  requires len >= 0;
  ensures \result <= len;
  ensures (\forall integer i; 0 <= i < len ==> (list1[i] == list2[i] ==> \result >= 1));
  ensures (\forall integer i; 0 <= i < len ==> (list1[i] != list2[i] ==> \result >= 0));
*/
size_t count_maximally_bisubset_element_list(int *list1, int *list2, size_t len) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant count <= i;
      loop invariant \forall integer k; 0 <= k < i ==> (list1[k] == list2[k] ==> count >= 1);
      loop invariant \forall integer k; 0 <= k < i ==> (list1[k] != list2[k] ==> count >= 0);
      loop invariant count <= len;
      loop assigns i, count;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (list1[i] == list2[i]) {
            //@ assert list1[i] == list2[i];
            count++;
            //@ assert count >= 1;
        } else {
            //@ assert list1[i] != list2[i];
            //@ assert count >= 0;
        }
        i++;
        //@ assert count <= i;
    }
    //@ assert i == len;
    //@ assert count <= len;
    return count;
}
