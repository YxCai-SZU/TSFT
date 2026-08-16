#include <stdint.h>

/*@
    requires ((l) > 0) && ((b) > 0) && ((l) * (l) + (b) * (b) <= 4294967295);
    ensures \result == l * l + b * b;
    assigns \nothing;
*/
uint32_t rectangle_diagonal_squared(uint32_t l, uint32_t b)
{
    // Variable declarations at the top
    uint32_t diagonal_squared;

    //@ assert ((l) > 0);
    //@ assert ((b) > 0);
    //@ assert l * l <= 4294967295;
    //@ assert b * b <= 4294967295;
    //@ assert l * l + b * b <= 4294967295;

    diagonal_squared = l * l + b * b;

    //@ assert diagonal_squared == l * l + b * b;

    return diagonal_squared;
}
