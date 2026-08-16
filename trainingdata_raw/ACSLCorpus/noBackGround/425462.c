#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (b / a) * c;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    // Variable declarations at scope top
    uint32_t div_result;
    uint32_t final_result;

    //@ assert c > 0 && a > 0;
    //@ assert a <= 100 && b <= 100 && c <= 100;
    //@ assert b / a <= 100;
    //@ assert (b / a) * c <= 10000;

    div_result = b / a;
    final_result = div_result * c;

    //@ assert final_result == (b / a) * c;
    return final_result;
}
