#include <stdint.h>

/*@
    requires (1 <= (n) <= 100) && (1 <= (m) <= 100);
    ensures \result == ((n) * (m));
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t m)
{
    //@ assert ((n) * (m)) <= 10000;
    return n * m;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int32_t func2(int32_t a, int32_t b)
{
    //@ assert ((a) * (b)) <= 10000;
    return a * b;
}
