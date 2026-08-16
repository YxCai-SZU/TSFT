#include <stdbool.h>

/*@
    predicate valid_range(integer a) = 1 <= a && a <= 100;
    
    logic integer absolute_difference(integer a, integer b) =
        a > b ? a - b : b - a;
*/

/*@
    requires valid_range(A) && valid_range(B);
    ensures \result >= 0;
    ensures \result == absolute_difference(A, B);
    assigns \nothing;
*/
int func(int A, int B)
{
    int C;
    int result;
    
    //@ assert valid_range(A) && valid_range(B);
    
    C = A - B;
    
    //@ assert C == A - B;
    
    if (C < 0) {
        result = -C;
        //@ assert result == B - A;
    } else {
        result = C;
        //@ assert result == A - B;
    }
    
    //@ assert result >= 0;
    //@ assert result == absolute_difference(A, B);
    
    return result;
}
