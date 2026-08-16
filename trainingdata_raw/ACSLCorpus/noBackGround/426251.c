#include <limits.h>

/*@
    requires (3 <= (a) && (a) <= 20 &&
        3 <= (b) && (b) <= 20);
    ensures \result == (((a) + (b)) * 2 - 5);
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;

    //@ assert a + b >= 6;
    //@ assert a + b <= 40;
    //@ assert (a + b) * 2 >= 12;
    //@ assert (a + b) * 2 <= 80;
    //@ assert (a + b) * 2 - 5 >= 7;

    result = (a + b) * 2 - 5;
    return result;
}
