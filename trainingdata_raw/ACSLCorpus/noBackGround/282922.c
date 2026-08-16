#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid(arr + (0 .. len-1));
    requires len >= 2;
    assigns \nothing;
    ensures \result == (len >= 2 && arr[0] == arr[len - 1]);
*/
bool is_palindromic_c(size_t len, int *arr) {
    // Variable declarations at top of scope
    bool res = false;
    
    //@ assert len >= 2;
    
    if (len < 2) {
        return false;
    }
    
    //@ assert len >= 2;
    
    if (arr[0] == arr[len - 1]) {
        res = true;
    } else {
        res = false;
    }
    
    //@ assert res == (len >= 2 && arr[0] == arr[len - 1]);
    return res;
}
