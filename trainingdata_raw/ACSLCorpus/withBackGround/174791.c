#include <stdbool.h>

/*@ predicate exists_min(int *list, integer len, integer val) =
      \exists integer i; 0 <= i < len && list[i] == val;
*/

/*@ predicate all_prev_exist(int *list, integer len, integer bound) =
      \forall integer j; 0 <= j < len && list[j] < bound ==>
        \exists integer k; 0 <= k < len && list[k] == list[j] - 1;
*/

/*@ lemma min_unique_lemma:
      \forall int *list, integer len, integer val;
        exists_min(list, len, val) && all_prev_exist(list, len, val) ==>
          \exists integer i; 0 <= i < len && list[i] == val &&
          (\forall integer j; 0 <= j < len && list[j] < val ==>
            \exists integer k; 0 <= k < len && list[k] == list[j] - 1);
*/

/*@
  requires length > 0;
  ensures exists_min(list_data, length, \result);
  ensures all_prev_exist(list_data, length, \result);
*/
int min_unique(int *list_data, int length) {
    int smallest;
    int index;
    
    smallest = list_data[0];
    index = 1;
    
    /*@ loop invariant 1 <= index <= length;
        loop invariant exists_min(list_data, index, smallest);
        loop invariant all_prev_exist(list_data, index, smallest);
        loop assigns smallest, index;
    */
    while (index < length) {
        //@ assert index < length;
        
        if (list_data[index] < smallest) {
            smallest = list_data[index];
        }
        
        //@ assert exists_min(list_data, index + 1, smallest);
        //@ assert all_prev_exist(list_data, index + 1, smallest);
        
        index = index + 1;
    }
    
    //@ assert exists_min(list_data, length, smallest);
    //@ assert all_prev_exist(list_data, length, smallest);
    
    return smallest;
}
