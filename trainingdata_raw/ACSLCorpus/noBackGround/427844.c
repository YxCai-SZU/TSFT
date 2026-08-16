#include <stdbool.h>

/*@
    requires ((a) > -9223372036854775808 && (a) < 9223372036854775807);
    requires ((b) > -9223372036854775808 && (b) < 9223372036854775807);
    requires ((c) > -9223372036854775808 && (c) < 9223372036854775807);
    ensures \result == (c >= a && c <= b);
*/
bool func(long a, long b, long c)
{
    // Variable declarations at top of scope
    bool result;

    // Proof block assertions
    //@ assert ((a) > -9223372036854775808 && (a) < 9223372036854775807);
    //@ assert ((b) > -9223372036854775808 && (b) < 9223372036854775807);
    //@ assert ((c) > -9223372036854775808 && (c) < 9223372036854775807);

    result = (a <= c) && (c <= b);
    return result;
}
