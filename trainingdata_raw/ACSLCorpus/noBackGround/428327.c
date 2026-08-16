#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * (n));
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert n * n <= 10000;
    return n * n;
}

/*@
    requires (1 <= (n) && (n) <= 100) && (1 <= (m) && (m) <= 100);
    ensures \result == ((n) * (m));
    assigns \nothing;
*/
uint32_t func2(uint32_t n, uint32_t m)
{
    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert (1 <= (m) && (m) <= 100);
    //@ assert n * m <= 10000;
    return n * m;
}
