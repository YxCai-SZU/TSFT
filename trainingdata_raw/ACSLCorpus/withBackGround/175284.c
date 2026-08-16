#include <stdint.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;

    logic integer func_spec(integer A, integer B) =
        (A * 2 > B) ? 0 : (B - A * 2);
*/

/*@
    requires valid_range(A) && valid_range(B);
    ensures \result >= 0;
    ensures \result <= B;
    ensures \result == func_spec(A, B);
    assigns \nothing;
*/
int32_t func(int32_t A, int32_t B)
{
    int32_t result;
    //@ assert valid_range(A) && valid_range(B);
    
    if (A * 2 > B)
    {
        //@ assert A * 2 > B;
        result = 0;
    }
    else
    {
        //@ assert A * 2 <= B;
        result = B - A * 2;
    }
    
    //@ assert result >= 0;
    //@ assert result <= B;
    //@ assert result == func_spec(A, B);
    return result;
}
