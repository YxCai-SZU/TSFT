#include <stdint.h>

/*@ predicate is_valid_X(integer X) = 0 <= X && X <= 1; */

/*@
    requires is_valid_X(X);
    ensures (X == 0 ==> \result == 1) && (X == 1 ==> \result == 0);
    assigns \nothing;
*/
int64_t func(int64_t X)
{
    // Variable declarations at top of scope
    int64_t result;
    
    //@ assert 0 <= X && X <= 1;
    //@ assert 1 - X == 1 - (int64_t)X;
    
    result = 1 - X;
    return result;
}
