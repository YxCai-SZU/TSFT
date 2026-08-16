#include <stdbool.h>

/*@
    requires ((a) >= -0x8000000000000000 && (a) <= 0x7fffffffffffffff);
    requires ((b) >= -0x8000000000000000 && (b) <= 0x7fffffffffffffff);
    requires ((c) >= -0x8000000000000000 && (c) <= 0x7fffffffffffffff);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(long long a, long long b, long long c)
{
    bool result;
    bool and_result;

    // Variable declarations at top
    result = a < b;
    and_result = result && (b < c);

    //@ assert and_result == (a < b && b < c);

    return and_result;
}
