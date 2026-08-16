#include <stdbool.h>

/*@
    requires (1 <= (a) <= 0xffff) && (1 <= (b) <= 0xffff);
    ensures \result == ( (a | b) == (a | (b & 0xffff)) );
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    bool result;
    //@ assert (1 <= (a) <= 0xffff) && (1 <= (b) <= 0xffff);
    result = ( (a | b) == (a | (b & 0xffff)) );
    //@ assert result == ( (a | b) == (a | (b & 0xffff)) );
    return result;
}
