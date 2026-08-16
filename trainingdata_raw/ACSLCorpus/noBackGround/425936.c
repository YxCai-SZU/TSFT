#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (a * b) / 2;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c)
{
    // Variable declarations at scope top
    uint64_t product;
    uint64_t result;
    uint64_t count;

    product = a * b;
    result = 0;
    count = product;

    //@ assert 1 <= product <= 10000;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 1 <= c <= 100;
        loop invariant count >= 0;
        loop invariant result == (product - count) / 2;
        loop invariant product == a * b;
        loop invariant count + 2 * result == product;
        loop assigns count, result;
    */
    while (count >= 2)
    {
        count -= 2;
        result += 1;
    }

    //@ assert result == (a * b) / 2;
    return result;
}
