#include <stdbool.h>

/*@
    requires \valid(v+(0..1));
    requires ((2) == 2 &&
    (v)[0] >= 0 &&
    (v)[1] <= 100);
    ensures \result == (v[0] == v[1]);
    assigns \nothing;
*/
bool func(int *v) {
    // Variable declarations at top of scope
    bool result;
    
    //@ assert v[0] >= 0;
    //@ assert v[1] <= 100;
    
    if (v[0] == v[1]) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
