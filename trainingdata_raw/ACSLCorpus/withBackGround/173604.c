#include <stdbool.h>

/*@
    predicate is_even(integer n) = n % 2 == 0;
    predicate is_odd(integer n) = n % 2 == 1;
*/

/*@
    requires 1 <= n <= 100;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n)
{
    int result;
    
    //@ assert n % 2 == 0 || n % 2 == 1;
    
    if (n % 2 == 0) {
        result = 1;
    } else if (n % 2 == 1) {
        result = 1;
    } else {
        // Unreachable branch
        result = -1;
    }
    
    //@ assert result >= 0;
    return result;
}
