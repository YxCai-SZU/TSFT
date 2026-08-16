#include <stdbool.h>
#include <stddef.h>

/*@ predicate element_in_range(int *list, integer len, integer element) =
      \exists integer i; 0 <= i < len && list[i] == element;
*/

/*@ lemma loop_invariant_maintained:
      \forall int *list, integer len, integer element, integer i;
      0 <= i <= len &&
      (\forall integer j; 0 <= j < i ==> list[j] != element) &&
      i < len &&
      list[i] != element ==>
      (\forall integer j; 0 <= j < i+1 ==> list[j] != element);
*/

/*@
  requires \valid(list + (0 .. len-1));
  assigns \nothing;
  ensures \result == true <==> element_in_range(list, len, element);
*/
bool contains_element(int *list, size_t len, int element) {
    size_t i = 0;
    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall integer j; 0 <= j < i ==> list[j] != element;
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (list[i] == element) {
            //@ assert element_in_range(list, len, element);
            return true;
        }
        i++;
    }
    //@ assert \forall integer j; 0 <= j < len ==> list[j] != element;
    return false;
}

/*@
  requires len > 0;
  requires \valid(list + (0 .. len-1));
  assigns \nothing;
  ensures \result == true <==> element_in_range(list, len, element);
*/
bool func(int *list, size_t len, int element) {
    size_t i = 0;
    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall integer j; 0 <= j < i ==> list[j] != element;
      loop invariant len > 0;
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (list[i] == element) {
            //@ assert element_in_range(list, len, element);
            return true;
        }
        i++;
    }
    //@ assert \forall integer j; 0 <= j < len ==> list[j] != element;
    return false;
}
