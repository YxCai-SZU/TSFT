#include <stdbool.h>

/*@
    predicate sorted(int *arr, integer len) =
        \forall integer i; 0 <= i < len - 1 ==> arr[i] <= arr[i + 1];
    
    predicate not_sorted(int *arr, integer len) =
        \exists integer i; 0 <= i < len - 1 && arr[i] > arr[i + 1];
*/

/*@
    requires len >= 0;
    requires \valid_read(arr + (0 .. len - 1));
    ensures \result ==> sorted(arr, len);
    ensures !\result ==> not_sorted(arr, len);
*/
bool is_sorted(int *arr, int len)
{
    int i;
    
    if (len <= 1) {
        return true;
    }
    
    i = 0;
    /*@
        loop invariant 0 <= i <= len - 1;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= arr[j + 1];
        loop assigns i;
        loop variant len - i;
    */
    while (i < len - 1) {
        //@ assert 0 <= i < len - 1;
        if (arr[i] > arr[i + 1]) {
            return false;
        }
        i++;
    }
    
    return true;
}
