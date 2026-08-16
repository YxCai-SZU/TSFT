#include <stdbool.h>
#include <stddef.h>

/*@
    predicate is_increasing(int *a, integer len) =
        len >= 3 && a[0] < a[1] && a[1] < a[2];
    
    predicate is_decreasing(int *a, integer len) =
        len >= 3 && a[0] > a[1] && a[1] > a[2];
    
    lemma increasing_or_decreasing:
        \forall int *a, integer len;
        len >= 3 ==>
        (is_increasing(a, len) || is_decreasing(a, len) || 
        (!is_increasing(a, len) && !is_decreasing(a, len)));
*/

/*@
    requires \valid_read(a + (0 .. 2));
    requires len >= 3;
    
    assigns \nothing;
    
    ensures \result == (a[0] < a[1] && a[1] < a[2] || a[0] > a[1] && a[1] > a[2]);
*/
bool func(int *a, size_t len) {
    bool result;
    
    //@ assert len >= 3;
    
    if (a[0] < a[1] && a[1] < a[2]) {
        //@ assert a[0] < a[1] && a[1] < a[2];
        result = true;
    } else if (a[0] > a[1] && a[1] > a[2]) {
        //@ assert a[0] > a[1] && a[1] > a[2];
        result = true;
    } else {
        //@ assert !(a[0] < a[1] && a[1] < a[2]) && !(a[0] > a[1] && a[1] > a[2]);
        result = false;
    }
    
    return result;
}
