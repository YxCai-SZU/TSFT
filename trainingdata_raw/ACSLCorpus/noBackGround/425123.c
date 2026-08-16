#include <stddef.h>
#include <stdbool.h>

/*@ requires \valid(arr + (0..len-1));
    requires ((k) >= 1 && (k) <= (len));
    assigns \nothing;
    ensures \result == ((arr)[(k)-1]);
*/
int find_kth_element(int* arr, size_t len, size_t k) {
    int result;
    size_t k_index;
    
    // Check if the given k is within the bounds of the array
    if (k < 1 || k > len) {
        return -1;  // Return -1 if k is out of bounds
    }

    // Since C uses 0-based indexing, we need to subtract 1 from k
    k_index = k - 1;
    
    //@ assert k_index < len;
    
    result = arr[k_index];
    return result;
}
