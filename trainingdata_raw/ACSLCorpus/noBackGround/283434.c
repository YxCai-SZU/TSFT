#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    requires ((a) <= (b)) && ((c) <= (d));
    ensures \result == b * d || \result == b * c || \result == a * d || \result == a * c;
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    // Variable declarations at top of scope
    long max_value;
    long temp_value;

    // Precondition assertions
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    //@ assert 1 <= d && d <= 100;
    //@ assert a <= b;
    //@ assert c <= d;

    // Overflow safety assertions
    //@ assert a * c <= 10000;
    max_value = a * c;

    //@ assert a * d <= 10000;
    temp_value = a * d;
    if (temp_value > max_value) {
        max_value = temp_value;
    }

    //@ assert b * c <= 10000;
    temp_value = b * c;
    if (temp_value > max_value) {
        max_value = temp_value;
    }

    //@ assert b * d <= 10000;
    temp_value = b * d;
    if (temp_value > max_value) {
        max_value = temp_value;
    }

    // Postcondition verification
    //@ assert max_value == b * d || max_value == b * c || max_value == a * d || max_value == a * c;
    return max_value;
}
