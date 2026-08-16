#include <stdbool.h>

/*@
    requires \valid(x + (0 .. 2));
    requires ((3) >= 3 &&
        1 <= (x)[0] && (x)[0] <= 100 &&
        1 <= (x)[1] && (x)[1] <= 100 &&
        1 <= (x)[2] && (x)[2] <= 100 &&
        ((x)[0] == (x)[1] || (x)[1] == (x)[2] || (x)[0] == (x)[2]));
    assigns \nothing;
    ensures (((x)[0] == (x)[1] && (\result) == (x)[2]) ||
        ((x)[1] == (x)[2] && (\result) == (x)[0]) ||
        ((x)[0] == (x)[2] && (\result) == (x)[1]));
*/
long func(long* x) {
    long result;

    //@ assert x[0] == x[1] || x[1] == x[2] || x[0] == x[2];
    
    if (x[0] == x[1]) {
        //@ assert x[0] == x[1];
        result = x[2];
    } else if (x[1] == x[2]) {
        //@ assert x[1] == x[2];
        result = x[0];
    } else {
        //@ assert x[0] == x[2];
        result = x[1];
    }
    
    return result;
}
