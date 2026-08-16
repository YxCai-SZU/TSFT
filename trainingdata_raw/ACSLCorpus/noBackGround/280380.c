#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(v + (0 .. 2));
    requires len >= 3;
    assigns \nothing;
    ensures \result == true <==> 
        (v[0] < v[1] && v[1] < v[2]) || 
        (v[0] > v[1] && v[1] > v[2]);
*/
bool func(unsigned long long *v, size_t len) {
    bool result;
    
    //@ assert len >= 3;
    
    if (v[0] < v[1] && v[1] < v[2]) {
        result = true;
        //@ assert ((len) >= 3 && (v)[0] < (v)[1] && (v)[1] < (v)[2]);
        return result;
    } else if (v[0] > v[1] && v[1] > v[2]) {
        result = true;
        //@ assert ((len) >= 3 && (v)[0] > (v)[1] && (v)[1] > (v)[2]);
        return result;
    } else {
        result = false;
        return result;
    }
}
