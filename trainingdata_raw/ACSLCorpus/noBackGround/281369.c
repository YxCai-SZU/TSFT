#include <stddef.h>

/*@
    requires (1 <= (K) <= (N) <= 50);
    ensures \result == ((N) - (K) + 1);
    assigns \nothing;
*/
size_t func(size_t N, size_t K)
{
    // Variable declarations at scope top
    size_t ans;
    
    //@ assert (1 <= (K) <= (N) <= 50);
    
    //@ assert ((N) - (K) + 1) <= 50 - 1 + 1;
    
    ans = N - K + 1;
    
    //@ assert ans == ((N) - (K) + 1);
    
    //@ assert 1 <= ans <= 50;
    
    return ans;
}
