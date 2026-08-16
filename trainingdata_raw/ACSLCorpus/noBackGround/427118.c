#include <stdbool.h>

/*@ requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (a + b == c || b + c == a || c + a == b);
    assigns \nothing;
*/
bool can_distribute_evenly(unsigned long a, unsigned long b, unsigned long c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert a + b <= 200;
    //@ assert b + c <= 200;
    //@ assert c + a <= 200;

    if (a + b == c || b + c == a || c + a == b) {
        result = true;
    } else {
        result = false;
    }
    return result;
}

/*@ requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (a + b == c || b + c == a || c + a == b);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long c)
{
    // Variable declarations at top of scope
    bool result;

    result = can_distribute_evenly(a, b, c);
    return result;
}
