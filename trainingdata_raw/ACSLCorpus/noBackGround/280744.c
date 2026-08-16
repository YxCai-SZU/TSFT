#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (white) <= (n) * (n));
    ensures \result == ((n) * (n) - (white));
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t white)
{
    int32_t ans;
    
    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= n * n && n * n <= 10000;
    //@ assert white + (n * n - white) == n * n;
    
    ans = n * n - white;
    
    //@ assert white + ans == n * n;
    return ans;
}
