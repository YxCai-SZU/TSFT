#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid(arr + (0..len-1));
    requires len > 0;
    requires (\forall integer i, j; 0 <= i <= j < (len) ==> (arr)[i] == (arr)[j]);
    ensures \exists integer i; 0 <= i < len && \result == arr[i];
*/
int search(int *arr, size_t len) {
    size_t low = 0;
    size_t high = len - 1;
    
    /*@ loop invariant 0 <= low <= high < len;
        loop invariant (\forall integer i, j; 0 <= i <= j < (len) ==> (arr)[i] == (arr)[j]);
        loop assigns low, high;
        loop variant high - low;
    */
    while (low < high) {
        size_t mid = low + (high - low) / 2;
        
        //@ assert mid >= low && mid <= high;
        
        bool cond1 = (mid == 0 || arr[mid] < arr[mid - 1]) && 
                     (mid == len - 1 || arr[mid] < arr[mid + 1]);
        bool cond2 = (mid == 0 || arr[mid] > arr[mid - 1]) && 
                     (mid == len - 1 || arr[mid] > arr[mid + 1]);
        
        if (cond1 || cond2) {
            return arr[mid];
        }
        
        if (arr[mid] > arr[(mid + 1) % len]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    return arr[low];
}
