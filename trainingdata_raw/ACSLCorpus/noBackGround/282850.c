#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((len) > 2 && \valid((v) + (0 .. (len)-1)));
    ensures \result == ((((0) >= 0 && (0) < (len)) ? (v)[(0)] : 0) < (((1) >= 0 && (1) < (len)) ? (v)[(1)] : 0) && 
                        (((1) >= 0 && (1) < (len)) ? (v)[(1)] : 0) < (((2) >= 0 && (2) < (len)) ? (v)[(2)] : 0));
*/
bool func(unsigned int *v, size_t len) {
    // Variable declarations at top of scope
    bool result;
    
    //@ assert ((len)) > 2;
    
    if (v[0] < v[1] && v[1] < v[2]) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
