#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 1000000000000000);
    ensures \result == (((a) / 500) * 1000 + (((a) % 500) / 5) * 5);
    assigns \nothing;
*/
uint64_t func(uint64_t a)
{
    uint64_t five_hundreds;
    uint64_t five_hundreds_mod;
    uint64_t fives;
    uint64_t result;

    five_hundreds = a / 500;
    five_hundreds_mod = a % 500;
    fives = five_hundreds_mod / 5;
    result = five_hundreds * 1000 + fives * 5;

    //@ assert five_hundreds == a / 500;
    //@ assert five_hundreds_mod == a % 500;
    //@ assert fives == five_hundreds_mod / 5;
    //@ assert result == five_hundreds * 1000 + fives * 5;
    //@ assert result == (((a) / 500) * 1000 + (((a) % 500) / 5) * 5);

    return result;
}
