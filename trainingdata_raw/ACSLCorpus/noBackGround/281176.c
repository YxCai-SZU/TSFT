#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(arr + (0 .. len-1));
    requires len > 0;
    ensures (\exists integer i; 0 <= i < (len) && (arr)[i] == (\result)) || \result == 0;
*/
int find_element(int* arr, size_t len) {
    size_t low = 0;
    size_t high = len - 1;
    int result = 0;
    
    /*@
        loop invariant 0 <= low <= high < len;
        loop invariant len > 0;
        loop assigns low, high, result;
        loop variant high - low;
    */
    while (low < high) {
        size_t mid = low + (high - low) / 2;
        
        //@ assert 0 <= mid < len;
        
        if (mid == 0 || arr[mid] != arr[mid - 1]) {
            result = arr[mid];
            //@ assert (\exists integer i; 0 <= i < (len) && (arr)[i] == (result));
            return result;
        } else if ((mid % 2 == 0 && arr[mid] == arr[mid - 1]) || 
                   (mid % 2 == 1 && arr[mid] == arr[mid + 1])) {
            low = mid + 1;
            //@ assert low <= high;
        } else {
            high = mid;
            //@ assert low <= high;
        }
    }
    
    result = 0;
    //@ assert result == 0;
    return result;
}
