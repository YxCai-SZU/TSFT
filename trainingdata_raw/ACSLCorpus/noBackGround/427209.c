#include <stdbool.h>

/*@
    requires ((2) == 2 &&
        \valid((v)) &&
        \valid((v) + 1) &&
        2 <= (v)[0] <= 100 &&
        2 <= (v)[1] <= 100);
    ensures \result == ((v[0]) * (v[1]) - (v[0]) - (v[1]) + 1);
    assigns \nothing;
*/
int func(int *v)
{
    int res;

    //@ assert 2 <= v[0] && v[0] <= 100;
    //@ assert 2 <= v[1] && v[1] <= 100;
    //@ assert v[0] * v[1] <= 10000;

    res = v[0] * v[1] - v[0] - v[1] + 1;
    return res;
}
