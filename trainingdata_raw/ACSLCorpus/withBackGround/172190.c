#include <stdbool.h>

/*@ predicate is_in_range(integer v) = 0 <= v && v <= 100; */

/*@ predicate all_in_range(int *arr, integer len) =
      \forall integer k; 0 <= k < len ==> is_in_range(arr[k]); */

/*@ predicate exists_at(int *arr, integer len, integer x, integer k) =
      0 <= k < len && arr[k] == x; */

/*@ predicate not_exists(int *arr, integer len, integer x) =
      \forall integer k; 0 <= k < len ==> arr[k] != x; */

/*@ lemma range_non_negative: 
      \forall integer len; 0 <= len && len <= 100 ==> len >= 0; */

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires 0 <= len && len <= 100;
  requires all_in_range(arr, len);
  ensures \result == true ==> \exists integer k; exists_at(arr, len, x, k);
  ensures \result == false ==> not_exists(arr, len, x);
*/
bool contains_element(int *arr, int len, int x) {
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall integer k; 0 <= k < i ==> arr[k] != x;
      loop assigns i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] == x) {
            //@ assert exists_at(arr, len, x, i);
            return true;
        }
        //@ assert arr[i] != x;
        i++;
        //@ assert \forall integer k; 0 <= k < i ==> arr[k] != x;
    }
    
    //@ assert i == len;
    //@ assert not_exists(arr, len, x);
    return false;
}
