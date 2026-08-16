#include <stdbool.h>

/*@
    requires \valid(array + (0..2));
    requires len > 2;
    assigns \nothing;
    ensures \result == (array[0] < array[1] && array[1] < array[2]);
*/
bool is_range_sorted(int* array, int len) {
    // Variable declarations at top of scope
    bool result;
    
    //@ assert len > 2;
    
    result = array[0] < array[1] && array[1] < array[2];
    return result;
}
