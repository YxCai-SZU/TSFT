#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 20 &&
        1 <= (b) && (b) <= 30 &&
        1 <= (c) && (c) <= 40);
    ensures \result == (a * b <= c);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert a <= 20;
    //@ assert b <= 30;
    //@ assert c <= 40;
    //@ assert a * b <= 600;

    result = (a * b <= c);
    return result;
}
