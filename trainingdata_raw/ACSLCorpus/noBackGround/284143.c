#include <stdbool.h>
#include <stdint.h>

/*@
    requires x <= 0xffffffff;
    requires y <= 0xffffffff;
    ensures \result == ((x | y) == (y | x));
    assigns \nothing;
*/
bool func(uint32_t x, uint32_t y)
{
    //@ assert (((x) | (y)) == ((y) | (x)));
    return (x | y) == (y | x);
}
