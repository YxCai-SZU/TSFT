#include <stdbool.h>

/*@
    predicate angle_in_range(integer x) = 0 <= x < 100;
    
    logic integer angle_sum(integer a, integer b, integer c) = a + b + c;
    
    lemma sum_range:
        \forall integer a, b, c;
        angle_in_range(a) && angle_in_range(b) && angle_in_range(c) ==>
        0 <= angle_sum(a, b, c) < 300;
*/

/*@
    requires angle_in_range(a) && angle_in_range(b) && angle_in_range(c);
    ensures \result == (a + b + c >= 180);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int sum;
    
    //@ assert 0 <= a < 100;
    //@ assert 0 <= b < 100;
    //@ assert 0 <= c < 100;
    
    //@ assert 0 <= a + b + c < 300;
    
    sum = a + b + c;
    result = (sum >= 180);
    
    return result;
}
