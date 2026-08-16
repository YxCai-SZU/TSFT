#include <stdbool.h>
/*@
    requires ((3) == 3 &&
        \valid((v) + (0 .. 2)) &&
        0 <= (v)[0] <= 100 &&
        0 <= (v)[1] <= 100 &&
        0 <= (v)[2] <= 100);
    ensures \result == (((v)[(0)]) <= ((v)[(2)]) && 
                       ((v)[(1)]) + ((v)[(0)]) >= ((v)[(2)]));
    assigns \nothing;
*/
bool func(int *v)
{
    int A;
    int B;
    int X;
    bool result;

    A = v[0];
    B = v[1];
    X = v[2];

    //@ assert ((v)[(1)]) + ((v)[(0)]) <= 200;
    result = (A <= X) && (B + A >= X);
    return result;
}
