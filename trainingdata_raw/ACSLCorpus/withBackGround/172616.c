#include <stdint.h>

/*@
    predicate is_multiply_by_four(integer x, integer result) =
        result == 4 * x;
*/

/*@
    requires x < 4294967295 / 4;
    ensures \result == 4 * x;
    assigns \nothing;
*/
uint32_t multiply_by_four(uint32_t x)
{
    uint32_t result;
    result = 4 * x;
    //@ assert is_multiply_by_four(x, result);
    return result;
}

/*@
    requires value < 4294967295 / 4;
    ensures \result == 4 * value;
    assigns \nothing;
*/
uint32_t multiply_by_four_times(uint32_t value)
{
    uint32_t result;
    result = multiply_by_four(value);
    //@ assert result == 4 * value;
    return result;
}

/*@
    assigns \nothing;
*/
void use_multiply_by_four_times(void)
{
    uint32_t result;
    result = multiply_by_four_times(4);
    //@ assert result == 16;
}

int main(void)
{
    use_multiply_by_four_times();
    return 0;
}
