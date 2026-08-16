#include <stddef.h>

/*@
    requires (1 <= (X) && (X) <= 100 &&
        1 <= (Y) && (Y) <= 100 &&
        (Y) % 2 == 0);
    ensures \result == ((X) + ((Y) / 2));
    assigns \nothing;
*/
size_t func(size_t X, size_t Y)
{
    size_t res;
    //@ assert Y / 2 <= 50;
    //@ assert X + (Y / 2) <= 150;
    res = X + (Y / 2);
    return res;
}
