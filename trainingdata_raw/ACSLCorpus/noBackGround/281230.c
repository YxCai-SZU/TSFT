#include <stdbool.h>

/*@
    requires ((a) > -0x8000000000000000 && (a) < 0x8000000000000000) && ((b) > -0x8000000000000000 && (b) < 0x8000000000000000) && ((c) > -0x8000000000000000 && (c) < 0x8000000000000000);
    ensures \result == true <==> a < b && b < c;
    assigns \nothing;
*/
bool func(long long a, long long b, long long c)
{
    int state = 0;

    //@ assert state == 0;
    if (a < b)
    {
        state += 1;
    }
    //@ assert state == (a < b ? 1 : 0);
    if (b < c)
    {
        state += 2;
    }
    //@ assert state == (((a) < (b) ? 1 : 0) + ((b) < (c) ? 2 : 0));
    //@ assert state == 3 <==> a < b && b < c;
    return state == 3;
}
