#include <stdint.h>

/*@
    requires (1 <= (a) <= 1000000 && 1 <= (b) <= 1000000);
    ensures \result >= 0 || \result == -1;
    ensures ((\result) >= 0 ==> ((\result) * 8 / 100 == (a) && (\result) * 10 / 100 == (b)));
*/
int64_t func(uint64_t a, uint64_t b)
{
    uint64_t x = 0;

    /*@
        loop invariant 0 <= x <= 1000001;
        loop invariant (1 <= (a) <= 1000000 && 1 <= (b) <= 1000000);
        loop assigns x;
        loop variant 1000001 - x;
    */
    while (x <= 1000000)
    {
        //@ assert x * 8 <= 8000000;
        //@ assert x * 10 <= 10000000;
        //@ assert x * 8 / 100 <= 80000;
        //@ assert x * 10 / 100 <= 100000;

        if ((x * 8 / 100) == a && (x * 10 / 100) == b)
        {
            return (int64_t)x;
        }
        x += 1;
    }
    return -1;
}

int main()
{
    return 0;
}
