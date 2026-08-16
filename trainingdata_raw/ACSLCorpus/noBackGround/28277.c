#include <stdbool.h>
#include <stddef.h>

/*@
    requires 0 <= len < 0x80000000;
    requires \valid_read(arr + (0 .. len-1));
    assigns \nothing;
    ensures \result == true <==> ((len) >= 2 && (arr)[(len) - 1] == 2 && (arr)[(len) - 2] == 2);
*/
bool check_2s_at_end(int *arr, size_t len) {
    bool result;
    
    if (len >= 2) {
        if (arr[len - 1] == 2 && arr[len - 2] == 2) {
            result = true;
        } else {
            //@ assert len >= 2 && (arr[len - 1] != 2 || arr[len - 2] != 2);
            result = false;
        }
    } else {
        //@ assert len < 2;
        result = false;
    }
    
    return result;
}
