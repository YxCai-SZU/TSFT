#include <stdbool.h>

/*@
    requires (-100 <= (a) <= 100 &&
        -100 <= (b) <= 100 &&
        -100 <= (c) <= 100);
    ensures \result == (c >= a && c <= b);
    assigns \nothing;
*/
bool func(long long a, long long b, long long c)
{
    // Variable declarations at scope top
    long long x;
    long long y;
    bool result;

    //@ assert (-100 <= (a) <= 100 &&         -100 <= (b) <= 100 &&         -100 <= (c) <= 100);
    //@ assert -200 <= a + b <= 200;

    x = a + b;
    y = a + b;
    result = (c >= a && c <= b);
    
    //@ assert result == (c >= a && c <= b);
    return result;
}
