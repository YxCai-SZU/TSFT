#include <stdbool.h>

/*@
    requires (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    ensures ((\result) == ((k) * 500 >= (x)));
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int x)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert k <= 100;
    //@ assert 500 * 100 == 50000;
    //@ assert 500 * 100 <= 50000;

    if (k * 500 >= x) {
        result = true;
    } else {
        result = false;
    }

    //@ assert ((result) == ((k) * 500 >= (x)));
    return result;
}
