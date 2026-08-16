#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 100);
    requires (0 <= (b) && (b) <= 100);
    requires (0 <= (c) && (c) <= 100);
    ensures \result <==> ((a) <= (c) && (c) <= (a) + (b));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert ((a) <= (c) && (c) <= (a) + (b)) <==> (a <= c && c <= a + b);

    result = (a <= c) && (c <= a + b);
    return result;
}
