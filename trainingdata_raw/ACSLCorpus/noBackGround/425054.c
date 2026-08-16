#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    // Variable declarations at scope top
    int64_t result;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    //@ assert ((a) * (b)) <= 10000;
    //@ assert ((a) * (b)) == ((a) * (b));

    result = a * b;
    //@ assert result == ((a) * (b));
    return result;
}
