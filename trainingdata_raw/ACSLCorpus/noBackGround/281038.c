#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures \result >= 0 || \result == -1;
    ensures ((\result) >= 0 ==>
        ((\result) * 8 / 100) == (a) &&
        ((\result) * 10 / 100) == (b));
*/
int32_t func(uint64_t a, uint64_t b)
{
    uint64_t x = 1;

    /*@
        loop invariant 1 <= x <= 100000;
        loop invariant (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
        loop assigns x;
        loop variant 100000 - x;
    */
    while (x < 100000)
    {
        //@ assert x * 8 <= 800000;
        //@ assert x * 10 <= 1000000;
        //@ assert (x * 8) / 100 <= 8000;
        //@ assert (x * 10) / 100 <= 10000;

        if (((x * 8) / 100) == a && ((x * 10) / 100) == b)
        {
            return (int32_t)x;
        }
        x += 1;
    }
    return -1;
}

int main()
{
    return 0;
}
