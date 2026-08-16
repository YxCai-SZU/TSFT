#include <stdint.h>

/*@
    requires ((a) >= 0 && (a) <= 4294967295 &&
        (b) >= 0 && (b) <= 4294967295 &&
        (a) * (b) <= 4294967295);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
uint32_t non_linear_arith_example(uint32_t a, uint32_t b)
{
    uint32_t result;

    //@ assert ((a) >= 0 && (a) <= 4294967295 &&         (b) >= 0 && (b) <= 4294967295 &&         (a) * (b) <= 4294967295);
    //@ assert ((a) * (b)) <= 4294967295;

    result = a * b;

    //@ assert result == ((a) * (b));
    return result;
}
