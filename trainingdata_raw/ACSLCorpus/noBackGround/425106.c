#include <stdbool.h>

/*@ requires
    \valid(v+(0..1)) &&
    ((v[0]) >= 1 && (v[0]) <= 16 &&
    (v[1]) >= 1 && (v[1]) <= 16 &&
    (v[0]) + (v[1]) <= 16);
    ensures
    \result == true <==> (v[0] <= 8 || v[1] <= 8);
*/
bool func(int v[2])
{
    //@ assert v[0] >= 1 && v[0] <= 16;
    //@ assert v[1] >= 1 && v[1] <= 16;
    //@ assert v[0] + v[1] <= 16;
    //@ assert (((v[0]) <= 8) || ((v[1]) <= 8));
    return v[0] <= 8 || v[1] <= 8;
}
