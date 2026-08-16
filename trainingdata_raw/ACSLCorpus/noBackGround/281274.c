#include <stdint.h>
/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result == ((1000 - (((n)) % 1000)) % 1000);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t remainder;
    uint32_t result;

    // First loop: compute n % 1000
    remainder = n;
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= remainder <= n;
        loop invariant remainder == n || remainder % 1000 == n % 1000;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 1000)
    {
        remainder -= 1000;
    }

    // Second loop: adjust remainder to be non-negative (already is)
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant remainder < 1000;
        loop invariant remainder == n - 1000 * (n / 1000 - 1) || remainder == n - 1000 * (n / 1000);
        loop assigns remainder;
        loop variant -remainder;
    */
    while (remainder < 0)
    {
        remainder += 1000;
    }

    // Third loop: compute 1000 - remainder
    result = 1000 - remainder;
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= result <= 1000;
        loop invariant result == 1000 - remainder || result == 1000 - remainder - 1000;
        loop assigns result;
        loop variant result;
    */
    while (result >= 1000)
    {
        result -= 1000;
    }

    // Fourth loop: adjust result to be non-negative
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant result < 1000;
        loop invariant result == 1000 - remainder || result == 1000 - remainder - 1000;
        loop assigns result;
        loop variant -result;
    */
    while (result < 0)
    {
        result += 1000;
    }

    // Final verification
    //@ assert result == ((1000 - (((n)) % 1000)) % 1000);

    return result;
}

int main()
{
    return 0;
}
