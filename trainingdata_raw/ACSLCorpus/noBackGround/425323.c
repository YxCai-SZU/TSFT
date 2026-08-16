#include <stdbool.h>

/*@
    requires (1 <= (a) <= 5000) && (1 <= (b) <= 5000) && (1 <= (c) <= 100000);
    ensures \result == (a + b >= c && c <= b * 2 + a);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert (1 <= (a) <= 5000);
    //@ assert (1 <= (b) <= 5000);
    //@ assert (1 <= (c) <= 100000);

    result = (a + b >= c) && (c <= b * 2 + a);
    return result;
}
