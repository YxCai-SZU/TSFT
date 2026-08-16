#include <stdbool.h>

/*@
    requires 100 <= N <= 999;
    ensures \result == true <==> ((N) / 100 == 7 || ((N) / 10) % 10 == 7 || (N) % 10 == 7);
    assigns \nothing;
*/
bool func(int N)
{
    unsigned int N_unsigned;
    unsigned int a0;
    unsigned int a1;
    unsigned int a2;
    bool result;

    N_unsigned = (unsigned int)N;
    a0 = N_unsigned / 100;
    a1 = (N_unsigned / 10) % 10;
    a2 = N_unsigned % 10;

    if (a0 == 7 || a1 == 7 || a2 == 7)
    {
        //@ assert a0 == 7 || a1 == 7 || a2 == 7;
        result = true;
    }
    else
    {
        //@ assert a0 != 7 && a1 != 7 && a2 != 7;
        result = false;
    }
    return result;
}
