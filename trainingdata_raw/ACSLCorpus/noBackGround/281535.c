#include <stdbool.h>

/*@
    requires (1 <= (k) && (k) <= 100) && (1 <= (x) && (x) <= 100000);
    ensures \result == (((k) * 500) >= x + 1);
    assigns \nothing;
*/
bool test_complex_inequality_6(unsigned int k, unsigned int x)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert k <= 100;
    //@ assert x <= 100000;
    //@ assert ((k) * 500) <= 50000;

    if (k * 500 - 1 >= x) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
