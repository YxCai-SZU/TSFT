#include <stdbool.h>

/*@
    predicate is_sorted(int *arr, integer len) =
        len == 3 ==> arr[0] < arr[1] && arr[1] < arr[2];
*/

/*@
    requires \valid(v + (0..2));
    ensures \result == (v[0] < v[1] && v[1] < v[2]);
    ensures \result <==> is_sorted(v, 3);
*/
bool func(int *v) {
    bool result;
    
    //@ assert v[0] < v[1] && v[1] < v[2] ==> is_sorted(v, 3);
    
    if (v[0] < v[1] && v[1] < v[2]) {
        result = true;
    } else {
        //@ assert !(v[0] < v[1] && v[1] < v[2]);
        result = false;
    }
    
    //@ assert result == (v[0] < v[1] && v[1] < v[2]);
    return result;
}
