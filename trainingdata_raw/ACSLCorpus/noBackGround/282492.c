#include <stddef.h>
#include <stdint.h>

/*@
    requires \valid(arr + (0 .. len-1));
    requires 1 <= k <= len;
    assigns \nothing;
    ensures \result == arr[k-1];
*/
int32_t find_kth_element(int32_t *arr, size_t len, size_t k)
{
    // Variable declarations at top of scope
    int32_t result;
    size_t index;

    //@ assert 1 <= k <= len;
    index = k - 1;
    
    //@ assert index < len;
    result = arr[index];
    
    //@ assert result == arr[k-1];
    return result;
}
