#include <stdint.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) + ((a) * (a)) + ((a) * (a) * (a)));
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at scope top
    int64_t result;

    //@ assert 1 <= a && a <= 10;
    //@ assert a * a <= 100;
    //@ assert a * a * a <= 1000;

    result = a + (a * a) + (a * a * a);
    return result;
}
