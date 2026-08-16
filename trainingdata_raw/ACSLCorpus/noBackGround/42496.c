#include <limits.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (a) <= (n) * (n));
    ensures \result == n * n - a;
    assigns \nothing;
*/
int func(int n, int a)
{
    // Declare all variables at the top
    int max_val;
    int result;
    
    //@ assert 0 <= n * n <= 10000;
    
    // Manual max implementation
    if (n * n > a) {
        max_val = n * n;
    } else {
        max_val = a;
    }
    
    //@ assert n * n >= 0 && a >= 0;
    
    result = n * n - a;
    return result;
}
