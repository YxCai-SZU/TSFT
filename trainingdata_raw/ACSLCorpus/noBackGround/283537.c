#include <stdbool.h>
/*@
    requires \valid(v+(0..1));
    requires ((2) == 2 &&
        \forall integer i; 0 <= i < (2) ==> (v)[i] <= 1000000000 &&
        (v)[0] >= 1 &&
        (v)[1] <= 1000000000);
    ensures \result == true <==> ((v[0]) <= (v[1]));
*/
bool func(int *v) {
    //@ assert ((2) == 2 &&         \forall integer i; 0 <= i < (2) ==> (v)[i] <= 1000000000 &&         (v)[0] >= 1 &&         (v)[1] <= 1000000000);
    //@ assert v[0] >= 1;
    //@ assert v[1] <= 1000000000;
    
    if (v[0] > v[1]) {
        //@ assert !((v[0]) <= (v[1]));
        return false;
    } else {
        //@ assert ((v[0]) <= (v[1]));
        return true;
    }
}
