#include <stdint.h>

/*@
    predicate bounds(integer x) = -16 <= x && x < 16;
    logic integer octuple_spec(integer x) = 8 * x;
*/

/*@
    requires bounds(x1);
    ensures \result == octuple_spec(x1);
    assigns \nothing;
*/
int8_t octuple(int8_t x1)
{
    int8_t x2;
    int8_t x4;
    int8_t result;

    //@ assert bounds(x1);
    x2 = x1 + x1;
    //@ assert x2 == 2 * x1;
    x4 = x2 + x2;
    //@ assert x4 == 4 * x1;
    result = x4 + x4;
    //@ assert result == 8 * x1;
    return result;
}

int main()
{
    int8_t n;
    n = octuple(10);
    //@ assert n == 80;
    return 0;
}
