#include <stdbool.h>

/*@
    requires (\valid((v)) &&
        (v)[0] >= 1 && (v)[0] <= 100 &&
        (v)[1] >= 1 && (v)[1] <= 100 &&
        ((v)[2] == 0 || (v)[2] == 1));
    ensures \result == ((v[1] * 2 + v[2]) >= v[0]);
    assigns \nothing;
*/
bool func(int *v)
{
    bool result;
    int h, a, b;

    h = v[0];
    a = v[1];
    b = v[2];

    //@ assert a * 2 <= 200;
    //@ assert a * 2 + b <= 201;

    result = (a * 2 + b) >= h;
    return result;
}
