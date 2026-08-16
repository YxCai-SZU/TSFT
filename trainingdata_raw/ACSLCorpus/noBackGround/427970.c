#include <stdbool.h>

/*@
    requires \valid(xs + (0..2));
    requires ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> (((xs)[i]) == 0 || ((xs)[i]) == 1));
    ensures \result == true <==> (((xs)[0] == 1 && (xs)[1] == 1 && (xs)[2] == 0) || ((xs)[0] == 0 && (xs)[1] == 0 && (xs)[2] == 1));
    assigns \nothing;
*/
bool func(int *xs) {
    bool result;

    //@ assert ((3) == 3 &&         \forall integer i; 0 <= i < (3) ==> (((xs)[i]) == 0 || ((xs)[i]) == 1));
    
    if (xs[0] == 1 && xs[1] == 1 && xs[2] == 0) {
        result = true;
        //@ assert ((xs)[0] == 1 && (xs)[1] == 1 && (xs)[2] == 0);
    } else if (xs[0] == 0 && xs[1] == 0 && xs[2] == 1) {
        result = true;
        //@ assert ((xs)[0] == 0 && (xs)[1] == 0 && (xs)[2] == 1);
    } else {
        //@ assert xs[0] != 1 || xs[1] != 1 || xs[2] != 0;
        //@ assert xs[0] != 0 || xs[1] != 0 || xs[2] != 1;
        result = false;
    }
    
    return result;
}
