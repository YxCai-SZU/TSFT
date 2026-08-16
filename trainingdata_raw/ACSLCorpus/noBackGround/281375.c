#include <stdbool.h>

/*@
    requires \valid(v + (0..1));
    requires v[0] >= 1 && v[0] <= 16;
    requires v[1] >= 1 && v[1] <= 16;
    requires v[0] + v[1] <= 16;
    ensures \result == true <==> (v[0] <= 8 && v[1] <= 8);
*/
bool func(int v[2]) {
    int a;
    int b;
    bool result;

    a = v[0];
    b = v[1];

    //@ assert a >= 1 && a <= 16;
    //@ assert b >= 1 && b <= 16;
    //@ assert a + b <= 16;

    result = (a <= 8 && b <= 8);
    return result;
}
