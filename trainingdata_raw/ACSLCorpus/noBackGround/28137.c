#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (x) <= 200);
    ensures \result == (x <= a + b && a <= x);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x)
{
    // Variable declarations at scope top
    bool left_side;
    bool right_side;
    bool result;

    //@ assert a <= 100;
    //@ assert b <= 100;
    //@ assert a + b <= 200;

    left_side = x <= a + b;
    right_side = a <= x;
    result = left_side && right_side;

    //@ assert result == (x <= a + b && a <= x);
    return result;
}
