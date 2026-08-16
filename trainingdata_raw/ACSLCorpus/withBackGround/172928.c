#include <stdbool.h>
#include <stddef.h>

/*@ predicate sorted(int *arr, integer len) =
      \forall integer i; 0 <= i < len - 1 ==> arr[i] <= arr[i + 1];
*/

/*@ predicate not_sorted(int *arr, integer len) =
      \exists integer i; 0 <= i < len - 1 && arr[i] > arr[i + 1];
*/

/*@ lemma sorted_empty: 
      \forall int *arr; sorted(arr, 0) && sorted(arr, 1);
*/

/*@ requires \valid(arr + (0 .. len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result == true ==> sorted(arr, len);
    ensures \result == false ==> not_sorted(arr, len);
*/
bool is_sorted(int *arr, size_t len) {
    if (len < 2) {
        //@ assert sorted(arr, len);
        return true;
    }

    size_t i = 0;
    /*@ loop invariant 0 <= i <= len - 1;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] <= arr[k + 1];
        loop assigns i;
        loop variant len - i - 1;
    */
    while (i < len - 1) {
        //@ assert 0 <= i <= len - 1;
        if (arr[i] > arr[i + 1]) {
            //@ assert not_sorted(arr, len);
            return false;
        }
        i++;
    }
    
    //@ assert sorted(arr, len);
    return true;
}
