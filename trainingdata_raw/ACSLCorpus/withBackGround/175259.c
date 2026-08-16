#include <stdbool.h>

/*@ predicate is_range_sorted(int *arr, integer n) =
    n > 2 &&
    arr[0] < arr[n-2] &&
    arr[n-2] < arr[n-1];
*/

/*@
    requires n > 2;
    requires \valid_read(arr + (0 .. n-1));
    ensures \result == (n > 2 && arr[0] < arr[n-2] && arr[n-2] < arr[n-1]);
*/
bool is_range_sorted(int *arr, int n) {
    // Variable declarations at the top
    bool result;
    
    //@ assert n > 2;
    
    // Check if the elements at the specific indices are in ascending order
    result = (arr[0] < arr[n-2]) && (arr[n-2] < arr[n-1]);
    
    //@ assert result == (n > 2 && arr[0] < arr[n-2] && arr[n-2] < arr[n-1]);
    
    return result;
}
