#include <stdbool.h>

/*@
    requires (1 <= (a) <= 5000 &&
        1 <= (b) <= 5000 &&
        1 <= (c) <= 10000);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= a <= 5000;
    //@ assert 1 <= b <= 5000;
    //@ assert 1 <= c <= 10000;
    //@ assert a + b <= 10000;

    result = (a + b >= c);
    return result;
}
