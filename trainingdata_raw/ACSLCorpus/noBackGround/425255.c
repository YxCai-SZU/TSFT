#include <stddef.h>
#include <stdbool.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    ensures (\exists integer i; 0 <= i < (len) && (\result) == (arr)[i]);
    assigns \nothing;
*/
int find_num_in_rotated_array(int* arr, size_t len) {
    size_t low = 0;
    size_t high = len - 1;
    
    /*@
        loop invariant 0 <= low <= high < len;
        loop invariant len > 0;
        loop assigns low, high;
        loop variant high - low;
    */
    while (low < high) {
        size_t mid = low + (high - low) / 2;
        
        //@ assert 0 <= mid < len;
        if (mid < len - 1 && arr[mid] > arr[mid + 1]) {
            //@ assert (\exists integer i; 0 <= i < (len) && ((arr)[mid + 1]) == (arr)[i]);
            return arr[mid + 1];
        }
        
        //@ assert 0 <= mid < len;
        if (mid > 0 && arr[mid] < arr[mid - 1]) {
            //@ assert (\exists integer i; 0 <= i < (len) && ((arr)[mid]) == (arr)[i]);
            return arr[mid];
        }
        
        if (arr[0] > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    //@ assert (\exists integer i; 0 <= i < (len) && ((arr)[0]) == (arr)[i]);
    return arr[0];
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
