#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (x) <= (n) * (n));
    ensures \result == n * n - x;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t x)
{
    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= x && x <= n * n;
    //@ assert n * n <= 10000;
    return n * n - x;
}

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n) * (n));
    ensures \result == n * n - m;
    assigns \nothing;
*/
uint32_t func2(uint32_t n, uint32_t m)
{
    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= m && m <= n * n;
    //@ assert n * n <= 10000;
    return n * n - m;
}
