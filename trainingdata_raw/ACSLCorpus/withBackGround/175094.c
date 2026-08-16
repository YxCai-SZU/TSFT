#include <stdbool.h>

/*@ predicate non_decreasing(int *list, integer len) =
      \forall integer i; 0 <= i < len - 1 ==> list[i] <= list[i + 1];
*/

/*@
  requires \valid(list + (0 .. len-1));
  requires len > 0;
  assigns \nothing;
  ensures \result == 1 <==> non_decreasing(list, len);
*/
bool non_decreasing(int *list, int len) {
    int i = 0;
    /*@
      loop invariant 0 <= i <= len - 1;
      loop invariant \forall integer j; 0 <= j < i ==> list[j] <= list[j + 1];
      loop assigns i;
      loop variant len - 1 - i;
    */
    while (i < len - 1) {
        //@ assert 0 <= i < len - 1;
        if (list[i] > list[i + 1]) {
            return false;
        }
        i++;
    }
    return true;
}
