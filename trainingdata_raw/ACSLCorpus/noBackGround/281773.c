#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (m) <= 100 &&
        (n) * (m) <= 4294967295);
    ensures \result == ((n) * (m));
    ensures \result >= 0;
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    // Variable declarations at scope top
    uint32_t product;
    int32_t result;

    //@ assert n <= 100;
    //@ assert m <= 100;
    //@ assert n * m <= 100 * 100;

    product = n * m;

    //@ assert product <= 10000;
    //@ assert product >= 0;

    result = (int32_t)product;
    return result;
}
