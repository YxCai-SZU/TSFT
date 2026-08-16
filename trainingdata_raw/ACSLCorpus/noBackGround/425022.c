#include <stdbool.h>
/*@
    requires ((2) == 2 &&
        \valid((v) + (0 .. 1)) &&
        1 <= (v)[0] <= 100 &&
        1 <= (v)[1] <= 100);
    ensures \result == (v[1] % v[0] == 0);
    assigns \nothing;
*/
bool func(int *v) {
    int v0;
    int v1;
    bool result;

    v0 = v[0];
    v1 = v[1];

    //@ assert v0 >= 1 && v0 <= 100;
    //@ assert v1 >= 1 && v1 <= 100;
    //@ assert v0 != 0;

    if (v1 % v0 == 0) {
        //@ assert v1 % v0 == 0;
        result = true;
    } else {
        //@ assert v1 % v0 != 0;
        result = false;
    }

    //@ assert result == (v1 % v0 == 0);
    return result;
}
