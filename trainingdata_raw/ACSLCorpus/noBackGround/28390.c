#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n) * (n));
    ensures \result >= 0 && \result <= 1;
    ensures \result == 1 ==> m == n * n;
    ensures \result == 0 ==> m != n * n;
*/
int32_t func(uint32_t n, uint32_t m)
{
    // Variable declarations at scope top
    int32_t nn;
    int32_t ans;
    
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= m <= n * n;
    
    //@ assert n * n <= 10000;
    nn = (int32_t)(n * n);
    
    if ((int32_t)m == nn)
    {
        ans = 1;
        //@ assert ans == 1;
        //@ assert m == n * n;
    }
    else
    {
        ans = 0;
        //@ assert ans == 0;
        //@ assert m != n * n;
    }
    
    //@ assert ans >= 0 && ans <= 1;
    return ans;
}
