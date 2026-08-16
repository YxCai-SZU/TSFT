#include <stdbool.h>

/*@
    requires ((a) >= -0x8000000000000000 && (a) <= 0x7FFFFFFFFFFFFFFF);
    requires ((b) >= -0x8000000000000000 && (b) <= 0x7FFFFFFFFFFFFFFF);
    requires ((c) >= -0x8000000000000000 && (c) <= 0x7FFFFFFFFFFFFFFF);
    ensures \result == true <==> (a < b && b < c);
    assigns \nothing;
*/
bool func(long long a, long long b, long long c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert ((a) >= -0x8000000000000000 && (a) <= 0x7FFFFFFFFFFFFFFF);
    //@ assert ((b) >= -0x8000000000000000 && (b) <= 0x7FFFFFFFFFFFFFFF);
    //@ assert ((c) >= -0x8000000000000000 && (c) <= 0x7FFFFFFFFFFFFFFF);

    if (a < b && b < c) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
