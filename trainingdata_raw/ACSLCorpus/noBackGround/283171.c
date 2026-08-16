#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100);
    ensures \result == ((a) * (a));
    ensures 1 <= \result && \result <= 10000;
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert 1 <= a && a <= 100;
    
    int64_t ans = a * a;
    
    //@ assert ans == ((a) * (a));
    //@ assert 1 <= ans && ans <= 10000;
    
    return ans;
}
