#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 3 <= a && a <= 20;
    predicate b_in_range(integer b) = 3 <= b && b <= 20;
    
    lemma result_property:
        \forall integer a, b, result;
        a_in_range(a) && b_in_range(b) ==>
        (result == a * 2 - 1 || result == b * 2 - 1 || 
         result == a + b || result == b * 2) ==>
        result >= 0;
*/

/*@
    requires a_in_range(a);
    requires b_in_range(b);
    ensures \result == a * 2 - 1 || \result == b * 2 - 1 || 
            \result == a + b || \result == b * 2;
    ensures \result >= 0;
*/
int func(int a, int b)
{
    int result;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    
    if (a > b + 1) {
        //@ assert a > b + 1;
        result = a * 2 - 1;
    } else if (b > a + 1) {
        //@ assert b > a + 1;
        result = b * 2 - 1;
    } else if (b == a) {
        //@ assert b == a;
        result = b * 2;
    } else {
        //@ assert b + a >= 0;
        result = b + a;
    }
    
    //@ assert result >= 0;
    return result;
}
