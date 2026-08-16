#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_index(int* arr, integer len, integer idx) =
        0 <= idx && idx < len;

    logic integer kth_element(int* arr, integer len, integer k) =
        arr[k-1];

    lemma kth_element_in_bounds:
        \forall int* arr, integer len, integer k;
        len > 0 && 1 <= k <= len ==> valid_index(arr, len, k-1);
*/

/*@
    requires \valid(arr + (0..len-1));
    requires len > 0;
    requires 1 <= k && k <= len;
    ensures \result == arr[k-1];
*/
int find_kth_element(int* arr, size_t len, size_t k)
{
    int ret;
    
    //@ assert len > 0;
    //@ assert 1 <= k && k <= len;
    
    if (k < 1 || k > len) {
        if (k < 1) {
            ret = arr[0];
        } else {
            ret = arr[len - 1];
        }
        return ret;
    }
    
    //@ assert k - 1 < len;
    ret = arr[k - 1];
    return ret;
}
