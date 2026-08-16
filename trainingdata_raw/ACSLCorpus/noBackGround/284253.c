#include <stddef.h>

/*@ requires k > 0;
    requires k <= len;
    requires \valid_read(arr + (0 .. len - 1));
    requires (\forall integer i, j; 0 <= i < j < (len) ==> (arr)[i] <= (arr)[j]);
    assigns \nothing;
    ensures \result == arr[k - 1];
*/
int find_kth_element(int *arr, size_t len, size_t k) {
    // Variable declarations at top of scope
    int kth_element_val;
    
    //@ assert k > 0 && k <= len;
    
    kth_element_val = arr[k - 1];
    
    //@ assert kth_element_val == arr[k - 1];
    
    return kth_element_val;
}
