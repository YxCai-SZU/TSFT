#include <stdbool.h>

/*@
    requires x <= 0x80000000 && x >= -0x80000000;
    ensures \result == 1 <==> (x & 1) == 0;
    assigns \nothing;
*/
bool is_even(int x)
{
    //@ assert x <= 0x80000000 && x >= -0x80000000;
    
    return (x & 1) == 0;
}
