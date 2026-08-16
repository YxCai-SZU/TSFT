#include <stdbool.h>

/*@
    predicate all_positive(int *arr, integer len) =
        \forall integer i; 0 <= i < len ==> arr[i] > 0;
*/

/*@
    requires len == 5;
    requires \valid(arr + (0 .. len-1));
    requires all_positive(arr, len);
    ensures \result <==> all_positive(arr, len);
    assigns \nothing;
*/
bool func(int *arr, int len) {
    // Variable declarations at top of scope
    bool result;
    
    //@ assert all_positive(arr, len);
    
    result = true;
    return result;
}
