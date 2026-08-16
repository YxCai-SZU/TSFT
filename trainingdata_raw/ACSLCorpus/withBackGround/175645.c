#include <stdbool.h>

/*@ predicate all_positive_range(int *arr, integer len, integer i) =
        \forall integer k; 0 <= k < i ==> arr[k] > 0;
*/

/*@
    requires \valid(arr + (0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result == true ==> arr[0] > 0;
    ensures \result == true ==> arr[0] > 0;
*/
bool all_positive(int *arr, int len) {
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant all_positive_range(arr, len, i);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] <= 0) {
            return false;
        }
        i++;
    }
    return true;
}
