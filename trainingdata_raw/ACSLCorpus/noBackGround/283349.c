#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 300000 &&
        1 <= (k) && (k) <= (n));
    assigns \nothing;
    ensures \result == (((n) - 1 - ((k) - 1)) + 1);
*/
size_t func(size_t k, size_t n)
{
    size_t count;
    //@ assert (1 <= (n) && (n) <= 300000 &&         1 <= (k) && (k) <= (n));
    count = (n - 1 - (k - 1)) + 1;
    //@ assert count == (((n) - 1 - ((k) - 1)) + 1);
    return count;
}
