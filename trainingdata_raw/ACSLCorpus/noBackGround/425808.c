#include <stdint.h>
#include <stdbool.h>

/*@
    requires n < 0xFFFFFFFF;
    ensures \result == (n % 2 != 0);
    assigns \nothing;
*/
bool is_odd(uint32_t n)
{
    //@ assert n < 0xFFFFFFFF;
    return (n % 2) != 0;
}

/*@
    requires n < 0xFFFFFFFF;
    requires a < 0xFFFFFFFF;
    requires n > 0;
    ensures \result <= n + a;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t a)
{
    //@ assert n < 0xFFFFFFFF;
    //@ assert a < 0xFFFFFFFF;
    //@ assert n > 0;
    if (n > a) {
        return n - a;
    } else {
        return 0;
    }
}

/*@
    requires n >= 0;
    requires a > 0;
    requires n <= 0x7FFFFFFFFFFFFFFF;
    requires a <= 0x7FFFFFFFFFFFFFFF;
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int64_t func2(int64_t n, int64_t a)
{
    //@ assert n >= 0;
    //@ assert a > 0;
    //@ assert n <= 0x7FFFFFFFFFFFFFFF;
    //@ assert a <= 0x7FFFFFFFFFFFFFFF;
    if (n > a) {
        return n - a;
    } else {
        return 0;
    }
}

/*@
    requires n <= 100;
    requires m <= 100;
    requires n * m <= 0xFFFFFFFF;
    ensures \result == n * m;
    assigns \nothing;
*/
uint32_t func3(uint32_t n, uint32_t m)
{
    //@ assert n <= 100;
    //@ assert m <= 100;
    //@ assert n * m <= 0xFFFFFFFF;
    return n * m;
}
