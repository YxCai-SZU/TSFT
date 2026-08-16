#include <stdint.h>

/*@
    requires ((a) >= 0 && (a) <= 23 && (b) >= 0 && (b) <= 23);
    ensures \result == ((a + b) % 24);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t result;

    //@ assert ((a) >= 0 && (a) <= 23 && (b) >= 0 && (b) <= 23);
    sum = a + b;
    //@ assert sum == a + b;
    //@ assert sum >= 0 && sum <= 48;
    result = sum % 24;
    //@ assert result == sum % 24;
    //@ assert result == ((a + b) % 24);
    return result;
}
