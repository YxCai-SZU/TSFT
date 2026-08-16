#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 10 &&
        1 <= (b) && (b) <= 10);
    ensures \result == (a * b <= 64);
    assigns \nothing;
*/
bool func(int a, int b)
{
    bool result;

    //@ assert (1 <= (a) && (a) <= 10 &&         1 <= (b) && (b) <= 10);
    //@ assert 1 <= a * b && a * b <= 100;

    result = (a * b <= 64);
    return result;
}
