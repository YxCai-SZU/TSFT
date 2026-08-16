#include <stdbool.h>

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == (a % 2 != 0 && b % 2 != 0);
    assigns \nothing;
*/
bool func(int a, int b)
{
    //@ assert 1 <= a <= 3;
    //@ assert 1 <= b <= 3;
    return a % 2 != 0 && b % 2 != 0;
}
