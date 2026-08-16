#include <stdbool.h>

/*@
    predicate A_in_range(integer a) = 1 <= a && a <= 100;
    predicate B_in_range(integer b) = 1 <= b && b <= 100;
    
    logic integer func_result(integer a, integer b) = 
        a >= b ? a - b : 0;
    
    lemma result_non_negative:
        \forall integer a, b;
        A_in_range(a) && B_in_range(b) ==> func_result(a, b) >= 0;
*/

/*@
    requires A_in_range(A) && B_in_range(B);
    ensures \result >= 0;
    ensures \result == func_result(A, B);
    assigns \nothing;
*/
int func(int A, int B)
{
    int result;
    
    //@ assert A_in_range(A) && B_in_range(B);
    
    if (A >= B) {
        //@ assert A - B >= 0;
        result = A - B;
    } else {
        //@ assert 0 >= 0;
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result == func_result(A, B);
    
    return result;
}
