#include <stdbool.h>

/*@
    predicate is_increasing(int *a, integer i) =
        a[i] < a[i+1] && a[i+1] < a[i+2];
    
    predicate is_decreasing(int *a, integer i) =
        a[i] > a[i+1] && a[i+1] > a[i+2];
*/

/*@
    requires \valid_read(v + (0..2));
    ensures \result == true <==> (is_increasing(v, 0) || is_decreasing(v, 0));
*/
bool func(int *v) {
    // Variable declarations at scope top
    bool result;
    
    //@ assert \valid_read(v + (0..2));
    
    if (v[0] < v[1] && v[1] < v[2]) {
        //@ assert is_increasing(v, 0);
        return true;
    }
    
    if (v[0] > v[1] && v[1] > v[2]) {
        //@ assert is_decreasing(v, 0);
        return true;
    }
    
    return false;
}
