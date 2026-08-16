#include <stdbool.h>
#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100) && (0 <= (m) && (m) <= (n) * (n));
    ensures (((\result) == 1 || (\result) == 0) &&
        ((\result) == 1 ==> (n) * (n) == (m)) &&
        ((\result) == 0 ==> (n) * (n) != (m)));
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    // Variable declarations at top of scope
    int32_t ans;
    uint32_t n_squared;
    
    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= m && m <= n * n;
    
    // Ensure multiplication doesn't overflow
    //@ assert n * n <= 10000;
    
    n_squared = n * n;
    
    if (n_squared == m) {
        ans = 1;
        //@ assert ans == 1;
        //@ assert n * n == m;
    } else {
        ans = 0;
        //@ assert ans == 0;
        //@ assert n * n != m;
    }
    
    //@ assert ans == 1 || ans == 0;
    //@ assert ans == 1 ==> n * n == m;
    //@ assert ans == 0 ==> n * n != m;
    
    return ans;
}
