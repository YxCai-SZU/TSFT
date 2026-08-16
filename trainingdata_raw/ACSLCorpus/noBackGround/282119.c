#include <stdbool.h>

/*@
    requires \valid(v+(0..1));
    requires ((2) == 2 &&
    1 <= (v)[0] <= 100 &&
    0 <= (v)[1] <= (v)[0]);
    ensures \result == (v[0] == v[1]);
    assigns \nothing;
*/
bool func(int *v) {
    //@ assert ((2) == 2 &&     1 <= (v)[0] <= 100 &&     0 <= (v)[1] <= (v)[0]);
    return v[0] == v[1];
}
