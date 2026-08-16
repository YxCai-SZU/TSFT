#include <stdint.h>

/*@
    requires (1 <= (n) <= 20);
    requires (1 <= (m) <= 20);
    ensures \result == (((((n)) * ((m))) / 2) + ((((n)) * ((m))) % 2));
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t m)
{
    // Variable declarations at scope top
    uint32_t product;
    uint32_t half;
    uint32_t remainder;
    uint32_t result;

    // Precondition verification
    //@ assert (1 <= (n) <= 20);
    //@ assert (1 <= (m) <= 20);

    // Product calculation
    product = n * m;
    //@ assert product == n * m;

    // Half calculation
    half = product / 2;
    //@ assert half == (((n) * (m)) / 2);

    // Remainder calculation
    remainder = product % 2;
    //@ assert remainder == (((n) * (m)) % 2);

    // Final result
    result = half + remainder;
    //@ assert result == half + remainder;

    // Postcondition verification
    //@ assert result == (((((n)) * ((m))) / 2) + ((((n)) * ((m))) % 2));

    return result;
}
