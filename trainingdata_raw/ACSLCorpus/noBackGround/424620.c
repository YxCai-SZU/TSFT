#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t sum;
    uint32_t result;

    sum = a + b;
    result = sum / 2;

    //@ assert result == sum / 2;
    
    if (sum % 2 != 0) {
        result += 1;
    }

    //@ assert result == sum / 2 + (sum % 2);
    //@ assert result == (((a) + (b) + 1) / 2);

    return result;
}
