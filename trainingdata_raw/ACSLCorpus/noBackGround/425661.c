#include <stdbool.h>

/*@
    requires \valid(v + (0..1));
    requires ((2) == 2 &&
        \forall integer i; 0 <= i < (2) ==> 1 <= (v)[i] <= 16);
    ensures \result == (((2) == 2 ? (v)[0] + (v)[1] : 0) >= 8);
    assigns \nothing;
*/
bool func(int *v) {
    int a;
    int b;
    bool result;

    a = v[0];
    b = v[1];

    //@ assert a >= 1 && a <= 16;
    //@ assert b >= 1 && b <= 16;

    if (a + b >= 8) {
        result = true;
        //@ assert ((2) == 2 ? (v)[0] + (v)[1] : 0) >= 8;
    } else {
        //@ assert a + b < 8;
        result = false;
        //@ assert ((2) == 2 ? (v)[0] + (v)[1] : 0) < 8;
    }

    return result;
}
