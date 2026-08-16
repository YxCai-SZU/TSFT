#include <stddef.h>
#include <stdbool.h>

/*@ predicate valid_height_array(int* arr, size_t len) =
        len > 0 &&
        \forall integer i; 0 <= i < len ==> arr[i] > 0;
*/

/*@ predicate ans_bounds(size_t ans, size_t len) =
        ans >= 0 && ans <= len;
*/

/*@ lemma preserves_heights:
        \forall int* arr, size_t len;
        valid_height_array(arr, len) ==> valid_height_array(arr, len);
*/

/*@ requires hs_len > 0;
    requires \valid_read(hs + (0 .. hs_len-1));
    requires valid_height_array(hs, hs_len);
    assigns \nothing;
    ensures ans_bounds(\result, hs_len);
*/
size_t func(const int* hs, size_t hs_len) {
    size_t max_height = 0;
    size_t ans = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= hs_len;
        loop invariant 0 <= ans <= index;
        loop invariant max_height == 0 || 
            \exists integer j; 0 <= j < index && hs[j] == (int)max_height;
        loop assigns max_height, ans, index;
    */
    while (index < hs_len) {
        int h = hs[index];
        
        //@ assert h > 0;
        
        if (max_height <= (size_t)h) {
            max_height = (size_t)h;
            ans += 1;
        }
        index += 1;
    }
    
    //@ assert ans_bounds(ans, hs_len);
    
    return ans;
}
