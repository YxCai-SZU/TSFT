#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b));
    ensures \result >= ((c) * (d));
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t product1;
    int64_t product2;
    int64_t result;

    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    //@ assert ((a) * (b)) <= 100000000;
    product1 = a * b;

    //@ assert (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    //@ assert ((c) * (d)) <= 100000000;
    product2 = c * d;

    if (product1 > product2)
    {
        result = product1;
        //@ assert result == ((a) * (b));
    }
    else
    {
        result = product2;
        //@ assert result == ((c) * (d));
    }

    //@ assert result >= ((a) * (b));
    //@ assert result >= ((c) * (d));
    return result;
}
