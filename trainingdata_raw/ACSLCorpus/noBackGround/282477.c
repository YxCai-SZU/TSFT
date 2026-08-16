#include <stdbool.h>

/*@
    requires (\valid((v)) && \valid((v)+1) && \valid((v)+2) &&
        1 <= (v)[0] <= 9 &&
        1 <= (v)[1] <= 9 &&
        1 <= (v)[2] <= 9);
    ensures \result == (((v[0]) * 100 + (v[1]) * 10 + (v[2])) % 4 == 0);
*/
bool func(int* v) {
    int v0;
    int v1;
    int v2;
    int sum;
    bool result;

    v0 = v[0];
    v1 = v[1];
    v2 = v[2];

    //@ assert v0 * 100 <= 900;
    //@ assert v1 * 10 <= 90;
    //@ assert v2 <= 9;
    //@ assert v0 * 100 + v1 * 10 + v2 <= 999;

    sum = v0 * 100 + v1 * 10 + v2;

    if (sum % 4 == 0) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
