#include <stdint.h>

/*@
    requires n <= 2896;
    ensures \result == n * (n + 1) / 2;
    ensures ((n) >= 0 && (n) <= 2896 && (\result) == (n) * ((n) + 1) / 2);
*/
uint32_t is_triangular(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t ret;

    //@ assert n <= 2896;
    //@ assert n * (n + 1) >= 0;
    //@ assert n * (n + 1) / 2 <= 4294967295;

    ret = n * (n + 1) / 2;
    
    //@ assert ret == n * (n + 1) / 2;
    return ret;
}
