#include <stdint.h>

/*@
    requires (1 <= (n) && 1 <= (m) &&
        (n) <= 100000 && (m) <= 100000 &&
        (n) * (m) <= 2000000000);
    ensures \result == ((((n) * (m))) / 2);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    uint64_t product;
    int32_t result;
    uint64_t temp;

    product = (uint64_t)n * (uint64_t)m;
    result = 0;
    temp = product;

    /*@
        loop invariant 0 <= temp <= product;
        loop invariant result == (product - temp) / 2;
        loop invariant temp + 2 * result == product;
        loop invariant temp <= product;
        loop assigns temp, result;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
        result += 1;
    }

    //@ assert result == product / 2;
    return result;
}
