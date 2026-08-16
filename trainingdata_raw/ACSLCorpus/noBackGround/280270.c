#include <stdbool.h>

/*@
    requires \valid(v + (0 .. 2));
    requires ((3) >= 3 &&
    \forall integer i; 0 <= i < (3) ==> ((v)[i] == 0 || (v)[i] == 1 || (v)[i] == 2));
    ensures \result == (((v)[(2)]) == 1 || 
                       (((v)[(1)]) == 1 && ((v)[(0)]) == 0) || 
                       (((v)[(1)]) == 0 && ((v)[(0)]) == 2));
*/
bool func(int *v) {
    //@ assert v[0] == 0 || v[0] == 1 || v[0] == 2;
    //@ assert v[1] == 0 || v[1] == 1 || v[1] == 2;
    //@ assert v[2] == 0 || v[2] == 1 || v[2] == 2;
    
    if (v[2] == 1 || (v[1] == 1 && v[0] == 0) || (v[1] == 0 && v[0] == 2)) {
        return true;
    } else {
        return false;
    }
}
