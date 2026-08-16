#include <stdint.h>

/*@
    predicate is_triangular(integer n, integer ret) =
        n >= 0 && n < 0x1000 &&
        ret == n * (n + 1) / 2 &&
        ret <= n * (n + 1);
*/

/*@
    requires n < 0x1000;
    ensures \result == n * (n + 1) / 2;
    ensures \result <= n * (n + 1);
*/
uint32_t is_triangular(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t ret;
    
    //@ assert n < 0x1000;
    
    ret = n * (n + 1) / 2;
    
    //@ assert ret == n * (n + 1) / 2;
    
    return ret;
}

int main()
{
    return 0;
}
