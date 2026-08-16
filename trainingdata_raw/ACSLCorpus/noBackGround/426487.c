#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result == ((a * 8) >= b);
    assigns \nothing;
*/
bool func(int a, int b)
{
    int a_local;
    int b_local;
    bool result;

    a_local = a;
    b_local = b;

    //@ assert 0 <= a_local <= 100;
    //@ assert 0 <= b_local <= 100;

    result = (a_local * 8) >= b_local;
    return result;
}
