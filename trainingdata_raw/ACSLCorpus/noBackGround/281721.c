#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (x) <= 100);
    ensures \result == (a <= x && x <= ((a) + (b)));
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x)
{
    // Variable declarations at top of scope
    bool is_greater_than_or_equal_a;
    bool is_less_than_or_equal_a_plus_b;
    bool result;

    //@ assert 0 <= a <= 100;
    //@ assert 0 <= b <= 100;
    //@ assert 0 <= x <= 100;
    //@ assert ((a) + (b)) <= 200;

    is_greater_than_or_equal_a = (a <= x);
    is_less_than_or_equal_a_plus_b = (x <= a + b);
    result = is_greater_than_or_equal_a && is_less_than_or_equal_a_plus_b;

    return result;
}
