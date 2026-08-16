#include <stdbool.h>

/*@
    requires 1 <= x <= 16;
    requires 1 <= y <= 16;
    requires x + y <= 16;
    ensures \result == true <==> (((x) <= 8) && ((y) <= 8));
*/
bool func(int x, int y)
{
    int max_val;
    bool result;

    //@ assert 1 <= x <= 16;
    //@ assert 1 <= y <= 16;
    //@ assert x + y <= 16;

    if (x > y) {
        max_val = x;
    } else {
        max_val = y;
    }

    if (max_val <= 8) {
        //@ assert (((x) <= 8) && ((y) <= 8));
        result = true;
    } else {
        //@ assert !(((x) <= 8) && ((y) <= 8));
        result = false;
    }

    //@ assert result == true <==> (((x) <= 8) && ((y) <= 8));
    return result;
}
