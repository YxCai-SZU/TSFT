#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((len) > 0 && \valid((arr) + (0 .. (len)-1)));
  assigns \nothing;
  ensures ((\result) ==> (len) >= 1);
*/
bool search_element(int *arr, size_t len) {
    // Variable declarations at top of scope
    size_t low;
    size_t high;
    size_t mid;
    bool condition1;
    bool condition2;
    bool condition3;
    bool condition4;
    bool condition5;
    
    // Precondition
    //@ assert len > 0;
    
    low = 0;
    high = len - 1;
    
    /*@ loop invariant 0 <= low <= high < len;
        loop invariant len > 0;
        loop assigns low, high, mid, condition1, condition2, condition3, condition4, condition5;
        loop variant high - low;
    */
    while (low < high) {
        mid = low + (high - low) / 2;
        
        condition1 = (mid == 0 || arr[mid] != arr[mid - 1]);
        condition2 = (mid == len - 1 || arr[mid] != arr[mid + 1]);
        
        //@ assert condition1 && condition2 ==> \true;
        if (condition1 && condition2) {
            return true;
        }
        
        condition3 = (mid % 2 == 0 && arr[mid] == arr[mid + 1]);
        condition4 = (mid % 2 == 1 && arr[mid] == arr[mid - 1]);
        condition5 = condition3 || condition4;
        
        //@ assert condition5 ==> \true;
        if (condition5) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    // Postcondition
    //@ assert !\true ==> len >= 1;
    return false;
}
