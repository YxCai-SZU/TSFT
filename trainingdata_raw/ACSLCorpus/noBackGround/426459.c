#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == true <==> ((a) * (c)) <= ((b) * (d));
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (1 <= (a) <= 10000) && (1 <= (c) <= 10000);
    //@ assert ((a) * (c)) <= 10000 * 10000;

    //@ assert (1 <= (b) <= 10000) && (1 <= (d) <= 10000);
    //@ assert ((b) * (d)) <= 10000 * 10000;

    result = (a * c) <= (b * d);
    return result;
}
