#include <stdbool.h>

/*@ predicate equal_length{L}(int *list1, int *list2, integer len1, integer len2) =
      len1 == len2;
*/

/*@ lemma len_nonnegative:
      \forall integer len1, integer len2;
        len1 >= 0 && len2 >= 0 ==> (len1 == len2) == (len1 == len2);
*/

/*@
  requires \valid(list1) && \valid(list2);
  requires len1 >= 0 && len2 >= 0;
  ensures \result <==> (len1 == len2);
  assigns \nothing;
*/
bool find_equal_vector_length(int *list1, int *list2, int len1, int len2) {
    //@ assert len1 >= 0;
    //@ assert len2 >= 0;
    return len1 == len2;
}
