#include <stdbool.h>
#include <limits.h>

/*@ predicate min_exists(int *arr, integer len, integer val) =
      \exists integer i; 0 <= i < len && arr[i] == val;
*/

/*@ predicate min_le_all(int *arr, integer len, integer val) =
      \forall integer i; 0 <= i < len ==> val <= arr[i];
*/

/*@ lemma min_preserved:
      \forall int *arr, integer len, integer idx, integer cur_min;
      0 <= idx < len ==>
      (\forall integer i; 0 <= i < idx ==> cur_min <= arr[i]) ==>
      (arr[idx] < cur_min ==> \forall integer j; 0 <= j <= idx ==> arr[idx] <= arr[j]) &&
      (arr[idx] >= cur_min ==> \forall integer j; 0 <= j <= idx ==> cur_min <= arr[j]);
*/

/*@ requires \valid(arr + (0..len-1));
    requires len > 0;
    requires len < INT_MAX/2;
    ensures min_exists(arr, len, \result);
    ensures min_le_all(arr, len, \result);
    assigns \nothing;
*/
int min_element(int *arr, int len) {
    int min_val;
    int i;
    
    min_val = arr[0];
    i = 1;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> min_val <= arr[j];
        loop invariant \exists integer j; 0 <= j < i && min_val == arr[j];
        loop assigns min_val, i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        i = i + 1;
    }
    
    //@ assert min_exists(arr, len, min_val);
    //@ assert min_le_all(arr, len, min_val);
    return min_val;
}
