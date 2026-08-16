#include <stdbool.h>

/*@
    requires \valid(v + (0 .. 1));
    requires ((2) == 2 &&
        \forall integer i; 0 <= i < (2) ==> (v)[i] >= 1 && (v)[i] <= 16 &&
        \forall integer i; 0 <= i < (2) ==> (v)[i] == (v)[i]);
    ensures \result == \true <==> ((v[0]) < (v[1]));
    assigns \nothing;
*/
bool func(int v[2]) {
    int v0;
    int v1;
    bool result;

    v0 = v[0];
    v1 = v[1];

    if (v0 < v1) {
        //@ assert v0 < v1;
        result = true;
    } else {
        //@ assert v0 >= v1;
        result = false;
    }

    return result;
}
