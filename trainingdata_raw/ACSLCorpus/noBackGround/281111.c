#include <stddef.h>
#include <stdbool.h>

/*@
    requires \valid(arr + (0..len-1));
    requires len > 0;
    requires 1 <= k && k <= len;
    ensures \result == ((arr)[(k) - 1]);
    assigns \nothing;
*/
int find_kth_element(int *arr, size_t len, size_t k)
{
    // Variable declarations at top of scope
    int result;
    size_t index;
    
    // Precondition ensures this is safe
    //@ assert 0 <= k - 1 && k - 1 < len;
    
    index = k - 1;
    //@ assert (0 <= (index) && (index) < (len));
    
    result = arr[index];
    //@ assert result == ((arr)[(k) - 1]);
    
    return result;
}
