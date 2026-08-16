#include <stdint.h>

/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100);
    requires A == (int64_t)A && B == (int64_t)B;
    ensures \result == ((A) > (B) * 2 ? (A) - ((B) * 2) : 0);
    ensures \result >= 0;
*/
int64_t func(int64_t A, int64_t B)
{
    int64_t result;

    //@ assert A >= 0 && B >= 0 && A <= 100 && B <= 100;
    
    if (A > B * 2)
    {
        result = A - (B * 2);
    }
    else
    {
        result = 0;
    }

    //@ assert result >= 0;
    return result;
}
