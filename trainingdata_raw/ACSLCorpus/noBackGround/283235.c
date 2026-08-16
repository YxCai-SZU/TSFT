#include <stddef.h>
#include <stdint.h>

/*@ requires \valid_read(arr + (0 .. len-1));
    requires (1 <= (k) && (k) <= (len));
    assigns \nothing;
    ensures \result == arr[k-1];
*/
int32_t find_kth_element(const int32_t* arr, size_t len, size_t k) {
    // Variable declarations at top of scope
    int32_t result;
    
    // Proof block translated to ACSL assertion
    //@ assert (1 <= (k) && (k) <= (len));
    
    // Index bounds verification
    //@ assert 0 <= k - 1 && k - 1 < len;
    
    result = arr[k - 1];
    return result;
}
