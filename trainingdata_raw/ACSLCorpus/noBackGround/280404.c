#include <stdbool.h>

/*@
    requires (1 <= (a) <= 3) && (1 <= (b) <= 3);
    ensures ((\result) == ((a) * (b) * (b) >= 0));
    assigns \nothing;
*/
bool func(int a, int b)
{
    // Variable declarations at scope top
    int c;
    bool result;

    //@ assert 1 <= a && a <= 3;
    //@ assert 1 <= b && b <= 3;
    //@ assert a * b <= 9;
    //@ assert a * b * b <= 27;

    c = a * b;
    result = (c * b >= 0);
    return result;
}
