#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result == ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t min_val1;
    uint32_t min_val2;
    uint32_t result;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);

    if (a < b) {
        min_val1 = a;
    } else {
        min_val1 = b;
    }
    //@ assert min_val1 == ((a) < (b) ? (a) : (b));

    if (c < d) {
        min_val2 = c;
    } else {
        min_val2 = d;
    }
    //@ assert min_val2 == ((c) < (d) ? (c) : (d));

    result = min_val1 + min_val2;
    //@ assert result == ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d));

    return result;
}
