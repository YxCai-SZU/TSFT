#include <stdint.h>

/*@
    predicate is_valid_X(integer x) = 0 <= x <= 1;
    predicate is_valid_A(integer a) = 0 <= a <= 1000000000000;
*/

/*@
    requires is_valid_X(X) && is_valid_A(A);
    ensures (X == 1 ==> \result == A + 1) && (X == 0 ==> \result == A);
    assigns \nothing;
*/
uint64_t func(uint64_t X, uint64_t A)
{
    //@ assert is_valid_X(X) && is_valid_A(A);
    
    if (X == 1)
    {
        //@ assert X == 1;
        return A + 1;
    }
    else
    {
        //@ assert X == 0;
        return A;
    }
}
