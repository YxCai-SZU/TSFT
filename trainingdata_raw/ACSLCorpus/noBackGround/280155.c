#include <stdbool.h>

/*@
    requires \valid(v + (0..5));
    requires (\valid((v) + (0..5)) &&
        0 <= (v)[0] && (v)[0] < (v)[1] && (v)[1] < (v)[2] && (v)[2] < (v)[3] && (v)[3] < (v)[4] && (v)[4] < (v)[5] && (v)[5] <= 123);
    ensures \result == ((((v)[4] - (v)[0] <= 2) ? 1 :
        ((v)[5] - (v)[1] <= 2) ? 1 :
        ((v)[2] - (v)[3] <= 2) ? 1 :
        ((v)[4] - (v)[3] <= 2) ? 1 :
        ((v)[5] - (v)[4] <= 2) ? 1 : 0) == 1);
*/
bool func(int *v)
{
    int len = 6;
    int i = 1;

    /*@
        loop invariant 1 <= i <= len;
        loop invariant (\valid((v) + (0..5)) &&
        0 <= (v)[0] && (v)[0] < (v)[1] && (v)[1] < (v)[2] && (v)[2] < (v)[3] && (v)[3] < (v)[4] && (v)[4] < (v)[5] && (v)[5] <= 123);
        loop assigns i;
    */
    while (i < len)
    {
        i = i + 1;
    }

    return (v[4] - v[0] <= 2) ||
           (v[5] - v[1] <= 2) ||
           (v[2] - v[3] <= 2) ||
           (v[4] - v[3] <= 2) ||
           (v[5] - v[4] <= 2);
}
