#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 100);
    ensures \result == ((x) * (x));
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    //@ assert (1 <= (x) && (x) <= 100);
    //@ assert ((x) * (x)) <= 10000;
    return x * x;
}

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (3 * (n) * (n));
    assigns \nothing;
*/
int32_t func2(int32_t n)
{
    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert n * n <= 10000;
    //@ assert 3 * n * n <= 30000;
    return n * n * 3;
}

/*@
    requires (1 <= (n) && (n) <= 100) && (1 <= (k) && (k) <= 100);
    ensures \result == ((n) * (n) * (k));
    assigns \nothing;
*/
int32_t func3(int32_t n, int32_t k)
{
    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert (1 <= (k) && (k) <= 100);
    //@ assert n * n <= 10000;
    //@ assert n * n * k <= 1000000;
    return n * n * k;
}
