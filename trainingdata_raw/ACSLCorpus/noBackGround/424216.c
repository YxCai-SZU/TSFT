#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100 && (a) * (b) <= 9223372036854775807);
    ensures \result == a * b;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert a * b <= 9223372036854775807;
    return a * b;
}
