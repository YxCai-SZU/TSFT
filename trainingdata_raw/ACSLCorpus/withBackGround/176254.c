#include <stdbool.h>
#include <stddef.h>

/*@ predicate contains_negative_cond(int *arr, integer len, integer i) =
      \forall integer j; 0 <= j < i ==> arr[j] >= 0;
*/

/*@ lemma loop_invariant_maintained:
      \forall int *arr, integer len, integer i;
        0 <= i < len && contains_negative_cond(arr, len, i) && arr[i] >= 0 ==>
        contains_negative_cond(arr, len, i+1);
*/

/*@ requires \valid(arr + (0..len-1));
    assigns \nothing;
    ensures \result == true ==> \exists integer i; 0 <= i < len && arr[i] < 0;
    ensures \result == false ==> \forall integer i; 0 <= i < len ==> arr[i] >= 0;
*/
bool contains_negative(int *arr, size_t len) {
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant contains_negative_cond(arr, len, i);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert contains_negative_cond(arr, len, i);
        if (arr[i] < 0) {
            //@ assert \exists integer j; 0 <= j < len && arr[j] < 0;
            return true;
        }
        //@ assert arr[i] >= 0;
        i++;
    }
    //@ assert \forall integer j; 0 <= j < len ==> arr[j] >= 0;
    return false;
}
