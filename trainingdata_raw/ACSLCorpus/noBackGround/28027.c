#include <stdbool.h>

/*@
    requires (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    ensures \result == (x <= (500 * (k)));
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int x)
{
    unsigned int en = 500;
    bool result;

    //@ assert (1 <= (k) <= 100 && 1 <= (x) <= 100000);

    if (x <= en * k) {
        //@ assert x <= (500 * (k));
        result = true;
    } else {
        //@ assert !(x <= (500 * (k)));
        result = false;
    }

    return result;
}
