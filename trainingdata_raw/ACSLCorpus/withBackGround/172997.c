#include <stdbool.h>

/*@
    predicate all_same(int *arr, integer len, integer i, int first) =
        \forall integer k; 0 <= k < i ==> arr[k] == first;

    predicate exists_different(int *arr, integer len, integer i, int first) =
        \exists integer k; 0 <= k < len && arr[k] != first;
*/

/*@
    requires len > 0;
    requires \valid_read(arr + (0 .. len-1));
    ensures \result == true ==> (\forall integer i; 0 <= i < len ==> arr[i] == arr[0]);
    ensures \result == false ==> (\exists integer i; 0 <= i < len && arr[i] != arr[0]);
*/
bool has_unique_element(int *arr, int len) {
    int first;
    int i;
    
    first = arr[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant all_same(arr, len, i, first);
        loop invariant len > 0;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        if (arr[i] != first) {
            //@ assert exists_different(arr, len, i+1, first);
            return false;
        }
        i = i + 1;
    }
    //@ assert all_same(arr, len, len, first);
    return true;
}
