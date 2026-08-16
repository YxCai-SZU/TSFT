#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 20 &&
        1 <= (a) && (a) <= 50 &&
        1 <= (b) && (b) <= 50);
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> (((n) * (a)) + (((n) - 1) * (b))) < ((n) * 50);
    ensures \result == 1 ==> (((n) * (a)) + (((n) - 1) * (b))) >= ((n) * 50);
*/
int32_t func(uint32_t n, uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t train;
    uint32_t taxi;
    int32_t result;

    //@ assert (1 <= (n) && (n) <= 20 &&         1 <= (a) && (a) <= 50 &&         1 <= (b) && (b) <= 50);
    
    //@ assert n * a <= 20 * 50;
    //@ assert (n - 1) * b <= 20 * 50;
    //@ assert n * 50 <= 20 * 50;

    train = (n * a) + ((n - 1) * b);
    taxi = n * 50;

    if (train < taxi)
    {
        result = 0;
        //@ assert (((n) * (a)) + (((n) - 1) * (b))) < ((n) * 50);
    }
    else
    {
        result = 1;
        //@ assert (((n) * (a)) + (((n) - 1) * (b))) >= ((n) * 50);
    }

    return result;
}
