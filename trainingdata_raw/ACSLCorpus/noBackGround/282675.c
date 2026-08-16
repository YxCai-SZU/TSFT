#include <stdint.h>
/*@
    requires (1 <= (A) && (A) <= 100 &&
        1 <= (B) && (B) <= 100);
    ensures \result == 0 || \result == 1;
    ensures ((\result) == 1 ==> (((A)) * ((B))) % 2 != 0);
    ensures ((\result) == 0 ==> (((A)) * ((B))) % 2 == 0);
*/
int32_t func(uint64_t A, uint64_t B)
{
    uint64_t C;
    int32_t is_odd;
    uint64_t temp;

    //@ assert (1 <= (A) && (A) <= 100 &&         1 <= (B) && (B) <= 100);
    //@ assert ((A) * (B)) <= 10000;

    C = A * B;
    is_odd = 0;
    temp = C;

    /*@
        loop invariant 1 <= A && A <= 100;
        loop invariant 1 <= B && B <= 100;
        loop invariant 0 <= temp && temp <= C;
        loop invariant temp % 2 == C % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }

    if (temp == 1)
    {
        is_odd = 1;
    }

    if (is_odd)
    {
        //@ assert ((A) * (B)) % 2 != 0;
        return 1;
    }
    else
    {
        //@ assert ((A) * (B)) % 2 == 0;
        return 0;
    }
}
