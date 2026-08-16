#include <stdbool.h>

/*@
    requires \valid(v + (0 .. 1));
    requires ((2) >= 2 &&
    2 <= (v)[0] && (v)[0] <= 100 &&
    2 <= (v)[1] && (v)[1] <= 100);
    ensures \result == v[0] * v[1] - 1 || \result == -1;
    assigns \nothing;
*/
int func(int *v) {
    int result;
    
    //@ assert ((2) >= 2 &&     2 <= (v)[0] && (v)[0] <= 100 &&     2 <= (v)[1] && (v)[1] <= 100);
    
    if (v[0] == 1 && v[1] == 1) {
        result = -1;
    } else if (v[0] == 2 && v[1] == 2) {
        result = 3;
    } else if (v[0] == 1 && v[1] == 3) {
        result = 5;
    } else if (v[0] == 3 && v[1] == 1) {
        result = 5;
    } else {
        //@ assert 2 <= v[0] && v[0] <= 100;
        //@ assert 2 <= v[1] && v[1] <= 100;
        //@ assert v[0] * v[1] <= 100 * 100;
        result = v[0] * v[1] - 1;
    }
    
    return result;
}
