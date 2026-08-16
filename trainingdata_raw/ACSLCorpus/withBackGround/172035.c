#include <stdbool.h>
/*@ predicate is_non_decreasing(int *arr, integer len) =
      \forall integer i; 0 <= i < len - 1 ==> arr[i] <= arr[i + 1];
*/

/*@ requires \valid(arr + (0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result == true ==> is_non_decreasing(arr, len);
    ensures \result == false ==> \exists integer i; 0 <= i < len - 1 && arr[i] > arr[i + 1];
*/
bool non_decreasing_consecutive_sum(int *arr, int len) {
    int index = 0;
    /*@ loop invariant 0 <= index <= len - 1;
        loop invariant \forall integer i; 0 <= i < index ==> arr[i] <= arr[i + 1];
        loop assigns index;
        loop variant len - index;
    */
    while (index < len - 1) {
        //@ assert 0 <= index < len - 1;
        if (arr[index] > arr[index + 1]) {
            return false;
        }
        index++;
    }
    return true;
}
