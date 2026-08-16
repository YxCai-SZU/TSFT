#include <stdint.h>

/*@
    requires -1000 <= x && x <= 1000;
    ensures -1000000 <= \result && \result <= 1000000;
    assigns \nothing;
*/
int32_t square_bound_check(int32_t x)
{
    int32_t result;
    //@ assert -1000 <= x && x <= 1000;
    result = x * x;
    //@ assert -1000000 <= result && result <= 1000000;
    return result;
}

/*@
    requires 0 <= length && length <= 1000 && 0 <= width && width <= 1000;
    ensures 0 <= \result && \result <= 1000000;
    assigns \nothing;
*/
uint32_t rectangle_area_bound_check(uint32_t length, uint32_t width)
{
    uint32_t result;
    //@ assert 0 <= length && length <= 1000 && 0 <= width && width <= 1000;
    result = length * width;
    //@ assert 0 <= result && result <= 1000000;
    return result;
}

/*@ assigns \nothing; */
int main()
{
    return 0;
}
