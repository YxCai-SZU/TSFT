#include <stdint.h>

/*@
    requires (0 <= (n) && (n) < 10000);
    ensures \result == ((n) * ((n) + 1) / 2);
    assigns \nothing;
*/
uint32_t triangular_number(uint32_t n)
{
    //@ assert n + 1 < 10001;
    //@ assert n * (n + 1) < 10000 * 10001;
    //@ assert n * (n + 1) / 2 < 50000 * 10001;
    return n * (n + 1) / 2;
}
