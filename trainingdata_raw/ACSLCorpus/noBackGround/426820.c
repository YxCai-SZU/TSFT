#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 5000 &&
        1 <= (b) && (b) <= 5000 &&
        1 <= (c) && (c) <= 10000);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= a && a <= 5000;
    //@ assert 1 <= b && b <= 5000;
    //@ assert 1 <= c && c <= 10000;

    result = (a + b >= c);
    return result;
}
