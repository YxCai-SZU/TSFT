#include <stdbool.h>

/*@
    requires \valid_read(v + (0 .. 2));
    requires ((len) >= 3 &&
        (v)[0] >= 1 && (v)[0] <= 100 &&
        (v)[1] >= 1 && (v)[1] <= 100 &&
        (v)[2] >= 1 && (v)[2] <= 100);
    ensures \result == (v[2] <= v[1] + v[0]);
*/
bool func(int *v, int len) {
    int v0;
    int v1;
    int v2;
    bool result;

    v0 = v[0];
    v1 = v[1];
    v2 = v[2];

    //@ assert v0 >= 1 && v0 <= 100;
    //@ assert v1 >= 1 && v1 <= 100;
    //@ assert v2 >= 1 && v2 <= 100;

    if (v0 < 1 || v1 < 1 || v2 < 1) {
        return false;
    }
    if (v0 > 100 || v1 > 100 || v2 > 100) {
        return false;
    }

    //@ assert len >= 3;
    result = (v2 <= v1 + v0);
    return result;
}
