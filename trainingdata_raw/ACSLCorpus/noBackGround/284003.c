#include <stdint.h>

/*@
    requires (-40 <= (a) <= 40);
    ensures \result == ((a) + 40);
    ensures \result >= 0;
    assigns \nothing;
*/
int32_t func(int32_t a)
{
    int32_t b;
    //@ assert (-40 <= (a) <= 40);
    b = a + 40;
    //@ assert b == ((a) + 40);
    //@ assert b >= 0;
    return b;
}
