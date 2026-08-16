#include <stdint.h>

/*@
    predicate bounds(uint32_t x, uint32_t y) = x <= UINT32_MAX - y;
    logic integer sum(integer x, integer y) = x + y;
*/

/*@
    requires bounds(x, y);
    ensures \result == sum(x, y);
    assigns \nothing;
*/
uint32_t adder(uint32_t x, uint32_t y)
{
    uint32_t ret;
    //@ assert bounds(x, y);
    ret = x + y;
    //@ assert ret == sum(x, y);
    return ret;
}

int main()
{
    uint32_t sum;
    sum = adder(10, 20);
    //@ assert sum == 30;
    return 0;
}
