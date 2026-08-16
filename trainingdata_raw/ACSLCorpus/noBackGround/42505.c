#include <stddef.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (h) && (h) <= 100 &&
        (h) % 2 == 0);
    ensures \result == (((a) + (b)) * (h) / 2);
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t h)
{
    // Variable declarations at scope top
    size_t result;

    //@ assert 1 <= a + b && a + b <= 200;
    //@ assert 1 <= (a + b) * h && (a + b) * h <= 20000;

    result = (a + b) * h / 2;
    //@ assert result == (((a) + (b)) * (h) / 2);
    return result;
}
