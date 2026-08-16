#include <stdbool.h>

/*@
    requires 0 <= x <= 100;
    requires 0 <= y <= 100;
    ensures \result == true <==> (x * 2 + 1) * 3 * y >= 10 * x * 3;
    assigns \nothing;
*/
bool func(int x, int y)
{
    int lhs;
    int rhs;
    bool result = false;

    //@ assert x * 2 <= 200;
    //@ assert (x * 2 + 1) * 3 <= 603;
    //@ assert 10 * x * 3 <= 3000;
    //@ assert 0 <= x * 2 + 1 <= 201;
    //@ assert 0 <= (x * 2 + 1) * 3 <= 603;
    //@ assert 0 <= (x * 2 + 1) * 3 * y <= 60300;
    //@ assert 0 <= 10 * x * 3 <= 3000;

    lhs = (x * 2 + 1) * 3 * y;
    rhs = 10 * x * 3;

    if (lhs >= rhs) {
        result = true;
    }

    //@ assert result == true <==> (x * 2 + 1) * 3 * y >= 10 * x * 3;
    return result;
}
