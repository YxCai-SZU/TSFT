#include <stddef.h>

/*@
    requires (1 <= (a) <= 10000);
    ensures \result <= 1000;
    ensures \result == ((a) % 1000 == 0 ? 0 : 1000 - ((a) % 1000));
    assigns \nothing;
*/
size_t func(size_t a)
{
    size_t r;
    size_t result;

    r = a % 1000;

    if (r == 0)
    {
        result = 0;
        //@ assert result == ((a) % 1000 == 0 ? 0 : 1000 - ((a) % 1000));
        return result;
    }
    else
    {
        //@ assert 1000 - r <= 1000;
        result = 1000 - r;
        //@ assert result == ((a) % 1000 == 0 ? 0 : 1000 - ((a) % 1000));
        return result;
    }
}
