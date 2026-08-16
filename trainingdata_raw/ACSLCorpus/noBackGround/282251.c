#include <stdint.h>
/*@
    requires (1 <= (n) && (n) <= 100);
    requires (0 <= (a) && (a) <= (n) * (n));
    ensures \result == ((((n)) * ((n))) - (a));
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t a)
{
    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert (0 <= (a) && (a) <= (n) * (n));
    //@ assert ((n) * (n)) <= 10000;
    return n * n - a;
}
