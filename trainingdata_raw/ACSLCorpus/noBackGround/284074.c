#include <stdint.h>

/*@
    requires (1 <= (A) <= 20 && 1 <= (B) <= 20);
    ensures \result == (((A) < 10 && (B) < 10) ? -1 :
        (((A) < 10 && (B) >= 10) || ((A) >= 10 && (B) < 10) || ((A) == 9 && (B) == 9)) ? 0 :
        (A) * (B));
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t B)
{
    int64_t result;

    //@ assert A >= 1 && A <= 20;
    //@ assert B >= 1 && B <= 20;

    if (A < 10 && B < 10)
    {
        result = -1;
        //@ assert result == -1 && A < 10 && B < 10;
        return result;
    }
    else if (A < 10 || B < 10)
    {
        result = 0;
        //@ assert result == 0 && ((A < 10 && B >= 10) || (A >= 10 && B < 10) || (A == 9 && B == 9));
        return result;
    }
    else
    {
        //@ assert A >= 10 && A <= 20;
        //@ assert B >= 10 && B <= 20;
        //@ assert A * B <= 400;
        result = A * B;
        //@ assert result == A * B && A >= 10 && B >= 10;
        return result;
    }
}
