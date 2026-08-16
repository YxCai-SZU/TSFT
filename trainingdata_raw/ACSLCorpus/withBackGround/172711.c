#include <limits.h>

/*@
    predicate bounds(integer v, integer low, integer high) =
        low <= v <= high;

    lemma intermediate_bounds:
        \forall integer x, y;
            bounds(x, 1, 10) && bounds(y, 1, 10) ==>
            bounds(x * y, 1, 100);

    lemma final_bounds:
        \forall integer x, y, z, xy;
            bounds(x, 1, 10) && bounds(y, 1, 10) && bounds(z, 1, 10) &&
            xy == x * y && bounds(xy, 1, 100) ==>
            bounds(xy * z, 1, 1000);
*/

/*@
    requires bounds(x, 1, 10);
    requires bounds(y, 1, 10);
    requires bounds(z, 1, 10);
    ensures \result == x * y * z;
    ensures bounds(\result, 1, 1000);
*/
int func(int x, int y, int z)
{
    int xy;
    int xyz;

    //@ assert bounds(x, 1, 10);
    //@ assert bounds(y, 1, 10);
    //@ assert bounds(x * y, 1, 100);
    xy = x * y;

    //@ assert bounds(z, 1, 10);
    //@ assert bounds(xy, 1, 100);
    //@ assert bounds(xy * z, 1, 1000);
    xyz = xy * z;

    return xyz;
}
