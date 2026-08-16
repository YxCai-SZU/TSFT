#include <stddef.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    // Variable declarations at top of scope
    size_t result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert ((a) * (b)) <= 10000;

    result = a * b;
    //@ assert result == ((a) * (b));
    return result;
}
