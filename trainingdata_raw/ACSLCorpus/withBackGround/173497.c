#include <stdbool.h>

/*@ predicate is_min(integer val, int* arr, integer len, integer idx) =
    idx >= 0 && idx < len && val == arr[idx];
*/

/*@ predicate all_ge(integer val, int* arr, integer len, integer bound) =
    \forall integer j; 0 <= j < bound ==> val <= arr[j];
*/

/*@ lemma min_exists: 
    \forall int* arr, integer len;
    len > 0 ==>
    \exists integer idx; is_min(arr[idx], arr, len, idx);
*/

/*@
    requires \valid(arr + (0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \exists integer i; 0 <= i < len && \result == arr[i];
    ensures \forall integer i; 0 <= i < len ==> \result <= arr[i];
*/
int find_min(int* arr, int len) {
    int min_val;
    int i;
    
    min_val = arr[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant all_ge(min_val, arr, len, i);
        loop invariant \exists integer j; 0 <= j < i && min_val == arr[j];
        loop assigns min_val, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        i = i + 1;
    }
    return min_val;
}
