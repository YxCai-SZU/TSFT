#include <stddef.h>
#include <limits.h>

/*@
    predicate valid_index(int *arr, integer len, integer idx) =
        0 <= idx && idx < len;
*/

/*@
    logic integer kth_element(int *arr, integer len, integer k) =
        arr[k - 1];
*/

/*@
    requires 1 <= k <= len;
    requires \valid_read(arr + (0 .. len-1));
    ensures \result == kth_element(arr, len, k);
    assigns \nothing;
*/
int find_kth_element(int *arr, size_t len, size_t k)
{
    int ret;
    size_t kth_index;
    
    // Check if k is within bounds
    if (k < 1 || k > len) {
        //@ assert k < 1 || k > len;
        return INT_MIN;
    }
    
    // Since array is 0-indexed, we need to subtract 1 from k
    kth_index = k - 1;
    
    // Return the kth element
    //@ assert valid_index(arr, len, kth_index);
    ret = arr[kth_index];
    
    return ret;
}
