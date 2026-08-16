#include <stdbool.h>

/*@
    requires ((1 <= ((a)) && ((a)) <= 100) && (1 <= ((b)) && ((b)) <= 100) && (1 <= ((c)) && ((c)) <= 100));
    ensures \result == (b - a == c - b);
    assigns \nothing;
*/
bool func(long a, long b, long c)
{
    // Variable declarations at top of scope
    bool result;
    long diff1;
    long diff2;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;

    // Prevent overflow/underflow verification
    //@ assert b - a >= -9223372036854775807 - 1 && b - a <= 9223372036854775807;
    //@ assert c - b >= -9223372036854775807 - 1 && c - b <= 9223372036854775807;
    //@ assert c - a >= -9223372036854775807 - 1 && c - a <= 9223372036854775807;

    diff1 = b - a;
    diff2 = c - b;
    result = (diff1 == diff2);

    //@ assert result == (b - a == c - b);
    return result;
}
