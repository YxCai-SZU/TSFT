#include <limits.h>

/*@
    requires (2 <= (a) <= 100 && 2 <= (b) <= 100);
    ensures \result == (((a) - 1) * ((b) - 1));
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    //@ assert 1 <= a - 1 <= 99;
    //@ assert 1 <= b - 1 <= 99;
    //@ assert 1 <= (a - 1) * (b - 1) <= 9801;
    result = (a - 1) * (b - 1);
    return result;
}
