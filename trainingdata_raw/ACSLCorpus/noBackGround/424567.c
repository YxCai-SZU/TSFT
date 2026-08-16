#include <stdbool.h>

/*@
    requires ((2) == 2 &&
        \valid((v) + (0 .. 1)) &&
        1 <= (v)[0] <= 100 &&
        1 <= (v)[1] <= 100);
    ensures \result == (((\old(v[0])) * 2) - (\old(v[1])) + 1);
    assigns \nothing;
*/
int func(int *v)
{
    int M;
    int D;
    int result;

    M = v[0];
    D = v[1];

    //@ assert M == \at(v[0], Pre);
    //@ assert D == \at(v[1], Pre);

    result = (M * 2) - D + 1;
    //@ assert result == (((M) * 2) - (D) + 1);

    return result;
}
