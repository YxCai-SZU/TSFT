#include <stdint.h>

/*@
    predicate sum_no_overflow(uint32_t a, uint32_t b) =
        a + b + 1 <= 0xFFFFFFFF;

    predicate product_no_overflow(uint32_t a, uint32_t b) =
        a * b <= 0xFFFFFFFF;

    logic integer sum_result(uint32_t a, uint32_t b) =
        a + b + 1;

    logic integer product_result(uint32_t a, uint32_t b) =
        a * b;
*/

/*@
    requires a <= 0xFFFFFFFF;
    requires b <= 0xFFFFFFFF;
    requires c <= 0xFFFFFFFF;
    requires sum_no_overflow(a, b);
    requires product_no_overflow(a, b);
    ensures \result == sum_result(a, b) || \result == product_result(a, b);
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert sum_no_overflow(a, b);
    //@ assert product_no_overflow(a, b);

    if ((uint64_t)a + (uint64_t)b + 1 < 0xFFFFFFFF)
    {
        result = a + b + 1;
        //@ assert result == sum_result(a, b);
    }
    else
    {
        //@ assert product_no_overflow(a, b);
        result = a * b;
        //@ assert result == product_result(a, b);
    }

    //@ assert result == sum_result(a, b) || result == product_result(a, b);
    return result;
}
