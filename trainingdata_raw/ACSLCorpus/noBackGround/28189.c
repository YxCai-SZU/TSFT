#include <stdint.h>

/*@ requires (-1290 <= (x) && (x) <= 1290);
    ensures \result == x * x;
    assigns \nothing;
 */
int32_t func(int32_t x)
{
    //@ assert (-1290 <= (x) && (x) <= 1290);
    //@ assert -1290*1290 <= x*x && x*x <= 1290*1290;
    return x * x;
}
