#include <limits.h>

/*@
    requires (-20 <= (x) && (x) <= 20) && (-20 <= (y) && (y) <= 20) && (-20 <= (z) && (z) <= 20);
    ensures (x == y && y == z) ==> \result == 3;
    ensures ((x == y || y == z || x == z) && !(x == y && y == z)) ==> \result == 2;
    ensures (x != y && y != z && x != z) ==> \result == 0;
    assigns \nothing;
*/
int func(int x, int y, int z)
{
    int res;

    if (x == y && y == z) {
        res = 3;
    } else if (x == y || y == z || x == z) {
        res = 2;
    } else {
        res = 0;
    }

    //@ assert (x == y && y == z) ==> res == 3;
    //@ assert ((x == y || y == z || x == z) && !(x == y && y == z)) ==> res == 2;
    //@ assert (x != y && y != z && x != z) ==> res == 0;
    //@ assert (-20 <= (x) && (x) <= 20) && (-20 <= (y) && (y) <= 20) && (-20 <= (z) && (z) <= 20);

    return res;
}
