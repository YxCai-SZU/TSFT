#include <stdint.h>

/*@
    requires 1 <= A <= 10000;
    requires 1 <= B <= 10000;
    requires 1 <= C <= 10000;
    requires 1 <= D <= 10000;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> ((A) > (B) ? (A) - (B) : (B) - (A)) <= C;
    ensures \result == 1 ==> ((A) > (B) ? (A) - (B) : (B) - (A)) > C;
*/
int32_t func(uint32_t A, uint32_t B, uint32_t C, uint32_t D)
{
    uint32_t diff;
    int32_t result;

    //@ assert 1 <= A <= 10000;
    //@ assert 1 <= B <= 10000;
    //@ assert 1 <= C <= 10000;
    //@ assert 1 <= D <= 10000;

    if (A > B)
    {
        diff = A - B;
    }
    else
    {
        diff = B - A;
    }

    if (diff <= C)
    {
        //@ assert diff <= C;
        result = 0;
    }
    else
    {
        //@ assert diff > C;
        result = 1;
    }

    //@ assert result == 0 || result == 1;
    return result;
}
