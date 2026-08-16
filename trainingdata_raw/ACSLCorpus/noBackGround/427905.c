#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result <= len;
    ensures \forall integer k; 0 <= k < \result - 1 ==> arr[k] <= arr[k+1];
*/
size_t find_min_length(const int *arr, size_t len) {
    size_t min_length = len;
    size_t i = 0;
    
    if (min_length > 0) {
        /*@
            loop invariant 0 <= i <= min_length - 1;
            loop invariant min_length <= len;
            loop invariant \forall integer k; 0 <= k < i ==> arr[k] <= arr[k+1];
            loop assigns i, min_length;
            loop variant min_length - i;
        */
        while (i < min_length - 1) {
            int current_val = arr[i];
            int next_val = arr[i + 1];
            
            //@ assert current_val == arr[i];
            
            if (current_val > next_val) {
                min_length = i + 1;
                break;
            }
            
            //@ assert current_val <= next_val;
            i += 1;
        }
    }
    
    //@ assert min_length <= len;
    return min_length;
}
