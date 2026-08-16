#include <stdbool.h>

/*@
    requires (1 <= (k) <= (n) <= 50);
    ensures \result == n - k + 1;
    assigns \nothing;
*/
int func(int n, int k)
{
    int max_val;
    int min_val;
    int result;

    //@ assert 1 <= k <= n <= 50;
    
    max_val = (k > 1) ? k : 1;
    //@ assert max_val == k || max_val == 1;
    
    min_val = (k < n) ? k : n;
    //@ assert min_val == k || min_val == n;
    
    result = n - k + 1;
    //@ assert result == n - k + 1;
    
    return result;
}
