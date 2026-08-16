#include <stdbool.h>
#include <stddef.h>

/*@ predicate equal_at_index(int *list1, int *list2, integer i) =
      list1[i] == list2[i];
*/

/*@ predicate has_equal_pair(int *list1, int *list2, integer len, integer i) =
      \exists integer k; 0 <= k < i && equal_at_index(list1, list2, k);
*/

/*@ lemma count_bounds:
      \forall int *list1, *list2, integer len, integer i, integer count;
        0 <= i <= len && 0 <= count <= i && 
        (has_equal_pair(list1, list2, len, i) ==> count >= 1) ==>
        count >= 0 && count <= len;
*/

/*@
  requires \valid(list1+(0..len-1)) && \valid(list2+(0..len-1));
  requires len < 0x80000000;
  requires len == \at(len, Pre);
  assigns \nothing;
  ensures 0 <= \result <= len;
  ensures \forall integer i; 0 <= i < len ==> 
            (list1[i] == list2[i] ==> \result >= 1);
*/
int count_equal_pairs(int *list1, int *list2, size_t len) {
    int count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant 0 <= count <= i;
      loop invariant \forall integer k; 0 <= k < i ==> 
                      (list1[k] == list2[k] ==> count >= 1);
      loop invariant len < 0x80000000;
      loop assigns i, count;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert i < len;
        if (list1[i] == list2[i]) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
