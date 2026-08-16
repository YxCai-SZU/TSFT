#include <stdbool.h>
#include <stddef.h>

/*@ predicate in_range(integer x, integer lower, integer upper) =
      lower <= x && x <= upper;
*/

/*@
  requires lower <= upper;
  requires \valid(list + (0 .. list_len-1));
  requires \valid(result + (0 .. list_len-1));
  assigns result[0 .. list_len-1], *result_len;
  ensures \forall integer i; 0 <= i < *result_len ==> in_range(result[i], lower, upper);
  ensures \forall integer i; 0 <= i < list_len && in_range(list[i], lower, upper) ==> 
          \exists integer j; 0 <= j < *result_len && result[j] == list[i];
*/
void filter_in_range(int *list, size_t list_len, int lower, int upper, int *result, size_t *result_len) {
    size_t index = 0;
    *result_len = 0;
    
    /*@
      loop invariant 0 <= index <= list_len;
      loop invariant *result_len <= index;
      loop invariant \forall integer i; 0 <= i < index && in_range(list[i], lower, upper) ==> 
                     \exists integer j; 0 <= j < *result_len && result[j] == list[i];
      loop invariant \forall integer i; 0 <= i < *result_len ==> in_range(result[i], lower, upper);
      loop assigns index, result[0 .. list_len-1], *result_len;
      loop variant list_len - index;
    */
    while (index < list_len) {
        int x = list[index];
        if (x >= lower && x <= upper) {
            //@ assert in_range(x, lower, upper);
            result[*result_len] = x;
            (*result_len)++;
        }
        index++;
    }
}
