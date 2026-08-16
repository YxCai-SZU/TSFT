#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_occurrence(int *list, integer len, integer i, int element) =
      (0 <= i < len) && (list[i] == element);
*/

/*@ predicate not_occurrence(int *list, integer len, integer i, int element) =
      (0 <= i < len) && (list[i] != element);
*/

/*@ lemma occurrence_implies_count:
      \forall int *list, integer len, int element, integer i, integer count;
      (0 <= i <= len) && (0 <= count <= i) &&
      (\forall integer j; 0 <= j < i && list[j] == element ==> count > 0) &&
      (0 <= i < len && list[i] == element) ==>
      count + 1 > 0;
*/

/*@ lemma non_occurrence_maintains_count:
      \forall int *list, integer len, int element, integer i, integer count;
      (0 <= i <= len) && (0 <= count <= i) &&
      (\forall integer j; 0 <= j < i && list[j] != element ==> count >= 0) &&
      (0 <= i < len && list[i] != element) ==>
      count >= 0;
*/

/*@ requires \valid(list + (0 .. len-1));
    requires len < 1000;
    assigns \nothing;
    ensures 0 <= \result <= len;
    ensures \forall integer i; 0 <= i < len && list[i] == element ==> \result > 0;
    ensures \forall integer i; 0 <= i < len && list[i] != element ==> \result >= 0;
*/
uint32_t count_occurrences(int *list, uint32_t len, int element) {
    uint32_t count = 0;
    uint32_t i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer j; 0 <= j < i && list[j] == element ==> count > 0;
        loop invariant \forall integer j; 0 <= j < i && list[j] != element ==> count >= 0;
        loop invariant len < 1000;
        loop assigns count, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (list[i] == element) {
            //@ assert list[i] == element;
            count = count + 1;
            //@ assert count > 0;
        } else {
            //@ assert list[i] != element;
            //@ assert count >= 0;
        }
        i = i + 1;
    }
    return count;
}
