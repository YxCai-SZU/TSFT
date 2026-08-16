#include <limits.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures \result >= 0;
    ensures \result == n - m * 2 || \result == 0;
    assigns \nothing;
*/
int func(int n, int m)
{
    int max_val;
    
    //@ assert (1 <= (n) <= 100 && 1 <= (m) <= 100);
    
    if (n - m * 2 > 0) {
        max_val = n - m * 2;
        //@ assert max_val == n - m * 2;
    } else {
        max_val = 0;
        //@ assert max_val == 0;
    }
    
    //@ assert max_val >= 0;
    //@ assert max_val == n - m * 2 || max_val == 0;
    
    return max_val;
}
