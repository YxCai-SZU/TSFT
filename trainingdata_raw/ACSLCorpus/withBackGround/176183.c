#include <limits.h>

/*@
    predicate a_in_range(integer a) = 2 <= a && a <= 100;
    predicate b_in_range(integer b) = 2 <= b && b <= 100;
    predicate both_in_range(integer a, integer b) = a_in_range(a) && b_in_range(b);
    
    lemma mul_no_overflow: \forall integer a, b; both_in_range(a, b) ==> a * b <= INT_MAX;
    lemma mul_no_underflow: \forall integer a, b; both_in_range(a, b) ==> a * b >= INT_MIN;
    lemma sub_no_overflow: \forall integer a, b, x; both_in_range(a, b) && x == a + b - 1 ==> (a * b) - x <= INT_MAX;
    lemma sub_no_underflow: \forall integer a, b, x; both_in_range(a, b) && x == a + b - 1 ==> (a * b) - x >= INT_MIN;
*/

/*@
    requires 2 <= a <= 100;
    requires 2 <= b <= 100;
    ensures \result == (a * b) - (a + b - 1);
    assigns \nothing;
*/
int func(int a, int b)
{
    int x;
    int result;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert both_in_range(a, b);
    
    x = a + b - 1;
    
    //@ assert mul_no_overflow: a * b <= INT_MAX;
    //@ assert mul_no_underflow: a * b >= INT_MIN;
    //@ assert sub_no_overflow: (a * b) - x <= INT_MAX;
    //@ assert sub_no_underflow: (a * b) - x >= INT_MIN;
    
    result = (a * b) - x;
    
    //@ assert result == (a * b) - (a + b - 1);
    return result;
}
