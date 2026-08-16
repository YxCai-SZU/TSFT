#include <stdbool.h>

/*@
    requires (1 <= (A) <= 100 && 1 <= (B) <= 100);
    ensures \result == ((A - B) > 0 ? (A - B) * 2 : 0);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int A, int B)
{
    int C;
    int result;

    C = A - B;

    //@ assert C >= -99 && C <= 99;

    if (C > 0)
    {
        //@ assert C > 0;
        result = C * 2;
    }
    else
    {
        result = 0;
    }

    //@ assert result >= 0;
    return result;
}
