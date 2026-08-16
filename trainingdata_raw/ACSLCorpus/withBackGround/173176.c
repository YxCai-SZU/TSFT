#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_vec(int *v, size_t len) =
        1 <= len <= 3 &&
        \forall integer i; 0 <= i < len ==> 1 <= v[i] <= 1000000000;

    logic integer vec_len(int *v, size_t len) = len;

    logic integer vec_at(int *v, size_t len, integer i) = v[i];
*/

/*@
    requires \valid(v + (0 .. len-1));
    requires valid_vec(v, len);
    ensures \result == (len == 3 && v[2] == v[1] + v[0] || len == 1 && v[0] == 0);
*/
bool func(int *v, size_t len) {
    bool result = false;
    
    //@ assert valid_vec(v, len);
    
    if (len == 3) {
        //@ assert vec_len(v, len) == 3;
        if (v[2] == v[1] + v[0]) {
            result = true;
        } else {
            result = false;
        }
    } else if (len == 1) {
        //@ assert vec_len(v, len) == 1;
        if (v[0] == 0) {
            result = true;
        } else {
            result = false;
        }
    } else {
        //@ assert vec_len(v, len) != 3 && vec_len(v, len) != 1;
        result = false;
    }
    
    return result;
}
