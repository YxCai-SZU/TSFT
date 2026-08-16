#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100);
    requires (1 <= (y) <= 100);
    ensures \result == true <==> (((x) * 2 + (100 - (x)) * 1) == y || ((x) * 2 + (100 - (x)) * 1) < y);
*/
bool func(int x, int y)
{
    int a;
    //@ assert (1 <= (x) <= 100);
    //@ assert (1 <= (y) <= 100);
    a = x * 2 + (100 - x) * 1;
    //@ assert a == ((x) * 2 + (100 - (x)) * 1);
    if (a == y || a < y) {
        return true;
    } else {
        return false;
    }
}
