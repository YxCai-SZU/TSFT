#include <stddef.h>

/*@
    requires (0 <= (a) && (a) <= 4500 && 0 <= (b) && (b) <= 4500);
    ensures \result >= 0;
    ensures \result == 0 || \result == 2 * b - a;
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    // Variable declarations at scope top
    size_t result;

    //@ assert (0 <= (a) && (a) <= 4500 && 0 <= (b) && (b) <= 4500);

    if (2 * b < a)
    {
        //@ assert 2 * b < a;
        result = 0;
    }
    else
    {
        //@ assert 2 * b >= a;
        result = 2 * b - a;
    }

    //@ assert result >= 0;
    //@ assert result == 0 || result == 2 * b - a;
    return result;
}
