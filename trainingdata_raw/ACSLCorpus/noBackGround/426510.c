#include <stdint.h>

/*@
    requires n < 2896;
    ensures \result == n * (n + 1) / 2;
    ensures \result <= n * n;
    assigns \nothing;
*/
uint32_t find_triangular_num(uint32_t n)
{
    //@ assert n < 2896;
    //@ assert n * (n + 1) <= 4294967295;
    //@ assert n * n <= 4294967295;
    //@ assert n * (n + 1) / 2 <= n * n;
    
    return n * (n + 1) / 2;
}
