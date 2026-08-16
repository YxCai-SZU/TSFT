#include <stdbool.h>

/*@
    requires (((a) == 1 || (a) == 2 || (a) == 3) &&
        ((b) == 1 || (b) == 2 || (b) == 3) &&
        (a) != (b));
    ensures (((\result) == 1 || (\result) == 2 || (\result) == 3) &&
        (\result) != (a) && (\result) != (b));
*/
int func(int a, int b)
{
    int res = 0;

    //@ assert a != b;

    if (a == 1) {
        if (b == 2) {
            res = 3;
        } else {
            res = 2;
        }
    } else if (a == 2) {
        if (b == 3) {
            res = 1;
        } else {
            res = 3;
        }
    } else {
        if (b == 1) {
            res = 2;
        } else {
            res = 1;
        }
    }

    //@ assert res == 1 || res == 2 || res == 3;
    //@ assert res != a;
    //@ assert res != b;

    return res;
}
