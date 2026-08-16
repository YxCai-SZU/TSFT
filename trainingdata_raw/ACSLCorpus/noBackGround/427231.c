#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100) && (1 <= (d) && (d) <= 100);
    ensures \result == (a * c <= b * d);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long c, unsigned long d)
{
    // Variable declarations at scope top
    bool result;

    //@ assert a * c <= 10000;
    //@ assert b * d <= 10000;

    result = (a * c <= b * d);
    return result;
}
