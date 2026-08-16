#include <stdbool.h>
#include <stddef.h>

/*@ predicate element_exists(int *arr, integer len, integer idx, int val) =
      (0 <= idx < len) && (arr[idx] == val);
*/

/*@ predicate is_min_in_prefix(int *arr, integer len, integer idx, int min_val) =
      \forall integer j; (0 <= j < idx) ==> (min_val <= arr[j]);
*/

/*@ predicate is_min_in_array(int *arr, integer len, int min_val) =
      \forall integer i; (0 <= i < len) ==> (min_val <= arr[i]);
*/

/*@ lemma min_element_exists: 
      \forall int *arr, integer len, integer idx, int min_val;
        (len > 0) && (idx <= len) && 
        (\exists integer j; (0 <= j < idx) && (arr[j] == min_val)) &&
        (\forall integer j; (0 <= j < idx) ==> (min_val <= arr[j])) ==>
        (\exists integer i; (0 <= i < len) && (arr[i] == min_val));
*/

/*@
    requires \valid(arr + (0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \exists integer i; (0 <= i < len) && (\result == arr[i]);
    ensures \forall integer i; (0 <= i < len) ==> (\result <= arr[i]);
*/
int find_min_element(int *arr, size_t len) {
    int min_element;
    size_t i;
    
    min_element = arr[0];
    i = 1;
    
    /*@
        loop invariant i <= len;
        loop invariant \exists integer j; (0 <= j < i) && (arr[j] == min_element);
        loop invariant \forall integer j; (0 <= j < i) ==> (min_element <= arr[j]);
        loop assigns min_element, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert i < len;
        if (arr[i] < min_element) {
            min_element = arr[i];
        }
        i++;
    }
    
    //@ assert \exists integer j; (0 <= j < len) && (arr[j] == min_element);
    //@ assert \forall integer j; (0 <= j < len) ==> (min_element <= arr[j]);
    return min_element;
}
