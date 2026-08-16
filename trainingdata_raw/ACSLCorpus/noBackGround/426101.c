#include <stdint.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures \result == (n - 1) / 2 + (m - 1) / 2 + 1;
*/
uint32_t func(uint32_t n, uint32_t m) {
    uint32_t result;

    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= m && m <= 100;
    //@ assert n - 1 >= 0;
    //@ assert m - 1 >= 0;
    //@ assert (n - 1) / 2 <= 49;
    //@ assert (m - 1) / 2 <= 49;
    //@ assert (n - 1) / 2 + (m - 1) / 2 <= 98;
    //@ assert (n - 1) / 2 + (m - 1) / 2 + 1 <= 99;

    result = (n - 1) / 2 + (m - 1) / 2 + 1;
    return result;
}
