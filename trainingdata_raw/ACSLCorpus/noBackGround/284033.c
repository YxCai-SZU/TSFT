#include <stdint.h>
/*@
    requires (1 <= (a) <= 10) && (1 <= (b) <= 10);
    ensures \result == ((a) + (b)) || \result == ((a) * (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) * (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t prod;

    //@ assert (1 <= (a) <= 10);
    //@ assert (1 <= (b) <= 10);
    //@ assert ((a) * (b)) <= 100;

    sum = a + b;
    prod = a * b;

    if (sum > prod)
    {
        //@ assert sum == ((a) + (b));
        //@ assert sum >= ((a) + (b));
        //@ assert sum >= ((a) * (b));
        return sum;
    }
    else
    {
        //@ assert prod == ((a) * (b));
        //@ assert prod >= ((a) + (b));
        //@ assert prod >= ((a) * (b));
        return prod;
    }
}
