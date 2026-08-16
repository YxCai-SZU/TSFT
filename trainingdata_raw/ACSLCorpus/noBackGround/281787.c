#include <stdint.h>

/*@
    requires (1 <= (a) <= 1000000000 &&
        1 <= (b) <= 1000000000 &&
        1 <= (c) <= 1000000000);
    ensures ((\result) >= 0 && (\result) <= 2);
    ensures ((\result) == 0 || (\result) == 1 || (\result) == 2);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    int32_t result;

    //@ assert (1 <= (a) <= 1000000000 &&         1 <= (b) <= 1000000000 &&         1 <= (c) <= 1000000000);

    if (c > a && c > b)
    {
        //@ assert c > a && c > b;
        result = 0;
    }
    else if (c <= a && c <= b)
    {
        //@ assert c <= a && c <= b;
        result = 2;
    }
    else
    {
        //@ assert c <= a || c <= b;
        result = 1;
    }

    //@ assert ((result) >= 0 && (result) <= 2);
    //@ assert ((result) == 0 || (result) == 1 || (result) == 2);
    return result;
}
