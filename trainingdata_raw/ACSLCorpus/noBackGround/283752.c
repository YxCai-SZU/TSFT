#include <stdbool.h>
#include <stddef.h>

/*@
    requires (1 <= (len) <= 3 &&
        \forall integer i; 0 <= i < (len) ==> 1 <= (v)[i] <= 100);
    ensures ((\result) == (
            ((len) == 1 && (v)[0] == 1) ||
            ((len) == 2 && (v)[0] == 2 && (v)[1] == 2) ||
            ((len) == 3 && (v)[0] == 3 && (v)[1] == 2 && (v)[2] == 3)
        ));
    assigns \nothing;
*/
bool func(int *v, size_t len) {
    bool result = false;
    
    //@ assert 1 <= len <= 3;
    
    if (len == 1) {
        //@ assert \forall integer i; 0 <= i < len ==> 1 <= v[i] <= 100;
        if (v[0] == 1) {
            result = true;
        } else {
            result = false;
        }
    } else if (len == 2) {
        //@ assert \forall integer i; 0 <= i < len ==> 1 <= v[i] <= 100;
        if (v[0] == 2 && v[1] == 2) {
            result = true;
        } else {
            result = false;
        }
    } else if (len == 3) {
        //@ assert \forall integer i; 0 <= i < len ==> 1 <= v[i] <= 100;
        if (v[0] == 3 && v[1] == 2 && v[2] == 3) {
            result = true;
        } else {
            result = false;
        }
    }
    
    return result;
}
