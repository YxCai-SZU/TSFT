#include <stdint.h>
/*@
    requires (0 <= (a) <= 1000000000000000) && (0 <= (b) <= 1000000000000000) && (0 <= (c) <= 1000000000000000);
    ensures \result >= 0 && \result <= b + c + 1 + a;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c)
{
    // Variable declarations
    uint64_t result;
    uint64_t remainder;
    uint64_t temp;

    // Precondition assertions
    //@ assert (0 <= (a) <= 1000000000000000) && (0 <= (b) <= 1000000000000000) && (0 <= (c) <= 1000000000000000);

    // Overflow safety checks
    //@ assert a + b + 1 <= 18446744073709551615 - b;
    //@ assert a + b + 1 + b <= 18446744073709551615;
    //@ assert b + c <= 18446744073709551615;

    // Main conditional logic
    if (a + b + 1 < c) {
        result = a + b + 1 + b;
        temp = a + b + 1;
    } else {
        result = b + c;
        temp = c;
    }

    // Remainder calculation
    remainder = temp % (b + 1);

    // Final adjustment
    if (remainder != 0) {
        result += 1;
    }

    // Postcondition verification
    //@ assert result >= 0;
    //@ assert result <= b + c + 1 + a;

    return result;
}
