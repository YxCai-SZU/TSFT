#include <stdint.h>

/*@
    predicate is_multiple_of_1000(integer n) = n % 1000 == 0;
    logic integer complement_to_1000(integer n) = 1000 - (n % 1000);
*/

/*@
    requires 1 <= n <= 100000;
    assigns \nothing;
    ensures is_multiple_of_1000(n) ==> \result == 0;
    ensures !is_multiple_of_1000(n) ==> \result == complement_to_1000(n);
*/
uint32_t func(uint32_t n)
{
    uint32_t three_digit;
    uint32_t remainder;
    uint32_t result;

    three_digit = n / 1000;
    remainder = n % 1000;

    if (remainder == 0)
    {
        //@ assert is_multiple_of_1000(n);
        result = 0;
    }
    else
    {
        //@ assert !is_multiple_of_1000(n);
        result = 1000 - remainder;
    }

    return result;
}
