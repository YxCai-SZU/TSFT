#include <stdbool.h>
#include <stddef.h>

/*@ requires len > 0;
    ensures (\exists integer i; 0 <= i < (len) && (arr)[i] == (\result));
*/
int find_element(int *arr, size_t len) {
    size_t low = 0;
    size_t high = len - 1;
    
    //@ assert 0 <= low <= high < len;
    //@ assert len > 0;
    
    /*@ loop invariant 0 <= low <= high < len;
        loop invariant len > 0;
        loop invariant low > 0 ==> (\exists integer i; 0 <= i < (len) && (arr)[i] == (arr[low]));
        loop invariant high < len - 1 ==> (\exists integer i; 0 <= i < (len) && (arr)[i] == (arr[high]));
        loop assigns low, high;
        loop variant high - low;
    */
    while (low < high) {
        //@ assert low < high;
        size_t mid = low + (high - low) / 2;
        
        //@ assert low <= mid <= high;
        
        bool left_condition = (mid == 0) || (arr[mid] != arr[mid - 1]);
        bool right_condition = (mid == len - 1) || (arr[mid] != arr[mid + 1]);
        
        if (left_condition && right_condition) {
            //@ assert ((0 <= (mid) < (len)) && ((arr)[(mid)] == (arr[mid])));
            //@ assert (\exists integer i; 0 <= i < (len) && (arr)[i] == (arr[mid]));
            return arr[mid];
        }
        
        size_t count;
        if (mid % 2 == 0) {
            count = (mid / 2) + 1;
        } else {
            count = mid / 2;
        }
        
        if (count % 2 == 0) {
            low = mid + 1;
            //@ assert low > 0;
        } else {
            high = mid;
            //@ assert high < len - 1;
        }
        
        //@ assert 0 <= low <= high < len;
    }
    
    //@ assert low == high;
    //@ assert ((0 <= (low) < (len)) && ((arr)[(low)] == (arr[low])));
    //@ assert (\exists integer i; 0 <= i < (len) && (arr)[i] == (arr[low]));
    return arr[low];
}
