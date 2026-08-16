#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate result_non_negative(integer r) = r >= 0;
    predicate result_formula(integer r, integer a, integer b) = 
        r == a - b * 2 || r == 0;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures result_non_negative(\result);
    ensures result_formula(\result, a, b);
*/
int func(int a, int b)
{
    int result;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    
    result = a - b * 2;
    
    if (result > 0) {
        //@ assert result_non_negative(result);
        //@ assert result_formula(result, a, b);
        return result;
    } else {
        //@ assert result <= 0;
        //@ assert result_formula(0, a, b);
        return 0;
    }
}
