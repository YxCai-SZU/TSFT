#include <stdbool.h>
/*@
    requires (\valid((v)) && \valid((v)+1) && \valid((v)+2) &&
        1 <= (v)[0] <= 20 &&
        1 <= (v)[1] <= 20 &&
        1 <= (v)[2] <= 20);
    ensures \result == (((v[0]) - 1) * ((v[1]) - 1) * ((v[2]) - 1));
    ensures 0 <= \result <= 6859;
*/
int func(int *v)
{
    int a;
    int b;
    int c;
    int result;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert 1 <= a <= 20;
    //@ assert 1 <= b <= 20;
    //@ assert 1 <= c <= 20;

    //@ assert 0 <= a - 1 <= 19;
    //@ assert 0 <= b - 1 <= 19;
    //@ assert 0 <= c - 1 <= 19;

    //@ assert (a - 1) * (b - 1) >= 0;
    //@ assert (a - 1) * (b - 1) <= 361;

    //@ assert (a - 1) * (b - 1) * (c - 1) >= 0;
    //@ assert (a - 1) * (b - 1) * (c - 1) <= 6859;

    result = (a - 1) * (b - 1) * (c - 1);
    return result;
}
