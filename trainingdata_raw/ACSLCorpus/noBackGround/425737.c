#include <stdbool.h>
#include <stddef.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result <= a;
    ensures \result == 0 || \result > 0;
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    size_t ans;
    
    if (b % a == 0) {
        ans = 0;
    } else {
        ans = a - 1;
    }
    
    //@ assert ans <= a;
    //@ assert ans == 0 || ans > 0;
    
    return ans;
}
