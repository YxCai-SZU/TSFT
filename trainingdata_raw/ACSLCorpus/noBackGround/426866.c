#include <stdbool.h>

/*@
    requires \valid(v+(0..2));
    requires ((3) == 3 &&
        1 <= (v)[0] <= 20 &&
        1 <= (v)[1] <= (v)[0] &&
        1 <= (v)[2] <= 20);
    ensures \result >= 0;
    ensures \result <= ((v[0]) - (v[1]) + (v[2]));
    assigns \nothing;
*/
int func(int *v) {
    int x;
    int y;
    int result;

    //@ assert v[0] >= v[1];
    //@ assert v[0] - v[1] <= 19;
    //@ assert v[0] - v[1] + v[2] <= 40;

    x = v[0] - v[1] + v[2];
    y = 0;
    
    if (x > y) {
        result = x;
    } else {
        result = y;
    }
    
    return result;
}
