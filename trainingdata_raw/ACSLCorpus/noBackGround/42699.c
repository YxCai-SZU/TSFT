#include <stdint.h>

/*@
    requires (1 <= (n) <= 100000);
    ensures (((n) % 100) < 10) ==> \result == 0;
    ensures (10 <= ((n) % 100) <= 99) ==> \result == 100 - ((n) % 100);
    ensures (((n) % 100) > 99) ==> \result == 0;
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t result;
    uint32_t mod_result;

    mod_result = n % 100;

    //@ assert (1 <= (n) <= 100000);
    //@ assert 0 <= mod_result <= 99;

    if (mod_result < 10)
    {
        //@ assert mod_result < 10;
        result = 0;
    }
    else if (mod_result > 99)
    {
        //@ assert mod_result > 99;
        result = 0;
    }
    else
    {
        //@ assert 10 <= mod_result <= 99;
        result = 100 - (int32_t)mod_result;
    }

    //@ assert result == ((((n)) % 100) < 10 ? 0 :         ((((n)) % 100) > 99 ? 0 : 100 - (((n)) % 100)));
    return result;
}
