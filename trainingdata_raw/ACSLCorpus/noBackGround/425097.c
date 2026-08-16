#include <stddef.h>

/*@ requires (1 <= (n) && (n) <= 10000);
    ensures \result <= 1000;
    ensures \result == 0 || n % 1000 != 0;
    assigns \nothing;
 */
size_t func(size_t n)
{
    size_t result;
    size_t remainder;

    if (n % 1000 == 0)
    {
        result = 0;
        return result;
    }
    else
    {
        remainder = n;
        /*@ loop invariant 1 <= n <= 10000;
            loop invariant 0 <= remainder <= n;
            loop invariant (n - remainder) % 1000 == 0;
            loop assigns remainder;
            loop variant remainder;
         */
        while (remainder >= 1000)
        {
            //@ assert remainder >= 1000;
            remainder -= 1000;
        }

        result = 1000 - remainder;
        return result;
    }
}
