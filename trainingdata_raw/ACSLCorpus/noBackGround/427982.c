#include <stddef.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
size_t func(size_t a)
{
    size_t a1;
    size_t a2;
    size_t a3;
    size_t result;

    a1 = a;
    //@ assert (1 <= (a1) <= 10);

    //@ assert 1 <= a * a <= 100;
    a2 = a * a;

    //@ assert 1 <= a * a * a <= 1000;
    a3 = a * a * a;

    result = a1 + a2 + a3;
    //@ assert result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    return result;
}
