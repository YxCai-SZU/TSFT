#include <stdint.h>

/*@
    requires ((n) <= 65535);
    ensures \result == ((n) * (n));
    ensures \result >= 0;
    assigns \nothing;
*/
uint32_t find_square_num(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t ret;

    //@ assert n <= 65535;
    //@ assert ((n) * (n)) <= 4294967295;
    //@ assert ((n) * (n)) >= 0;

    ret = n * n;

    //@ assert ret == ((n) * (n));
    //@ assert ret >= 0;

    return ret;
}
