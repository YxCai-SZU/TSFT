#include <stdbool.h>

/*@
    requires (0 <= (n) <= 1 && 0 <= (x) <= 1);
    ensures \result == 1 - n || \result == x;
    assigns \nothing;
*/
int func(int n, int x)
{
    int result;
    
    //@ assert (0 <= (n) <= 1 && 0 <= (x) <= 1);
    
    if (n == 1) {
        result = 1 - n;
    } else {
        result = x;
    }
    
    //@ assert result == 1 - n || result == x;
    
    return result;
}
