#include <stdbool.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (2 * 3 * (r));
    assigns \nothing;
*/
int func(int r)
{
    int pi = 3;
    int circumference;

    //@ assert 2 * 3 * r == 2 * pi * r;
    circumference = 2 * pi * r;
    return circumference;
}
