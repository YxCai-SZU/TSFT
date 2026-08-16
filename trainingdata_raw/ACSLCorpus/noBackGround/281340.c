#include <stdbool.h>
#include <stdint.h>

/*@
    requires 0 <= a <= 0xffffffff;
    requires 0 <= b <= 0xffffffff;
    ensures \result == true <==> (((a) | (b)) == 0xffffffff);
 */
bool func(uint32_t a, uint32_t b)
{
    //@ assert (a | b) == 0xffffffff || (a | b) != 0xffffffff;
    return (a | b) == 0xffffffff;
}
