#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert ((a) * (b)) <= 10000;
    return a * b;
}

/*@
    requires x > 0;
    requires y > 0;
    requires z > 0;
    ensures \result == ((x) * (y) + (z) * ((x) + (y)));
    assigns \nothing;
*/
int32_t non_linear_arith_example(int32_t x, int32_t y, int32_t z)
{
    //@ assert ((x) * (y) + (z) * ((x) + (y))) == x * y + z * x + z * y;
    return x * y + z * (x + y);
}
