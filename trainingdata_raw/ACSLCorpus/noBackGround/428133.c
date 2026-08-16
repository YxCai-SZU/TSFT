#include <stdbool.h>

/*@
    requires \valid(v + (0..2));
    requires ((3) >= 3 &&
        1 <= (v)[0] <= 100 &&
        1 <= (v)[1] <= 100 &&
        1 <= (v)[2] <= 500);
    ensures \result == (v[0] * v[1] >= v[2]);
    assigns \nothing;
*/
bool func(int *v) {
    bool result;
    
    //@ assert v[0] * v[1] <= 10000;
    
    result = (v[0] * v[1] >= v[2]);
    return result;
}
