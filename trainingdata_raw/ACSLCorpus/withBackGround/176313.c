#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10;

    logic integer sum_assoc1(integer a, integer b, integer c) = (a + b) + c;
    logic integer sum_assoc2(integer a, integer b, integer c) = a + (b + c);
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == sum_assoc1(a, b, c) || \result == sum_assoc2(a, b, c);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int s1;
    int s2;
    
    //@ assert a + b >= 2 && a + b <= 20;
    s1 = a + b;
    
    //@ assert s1 >= 2 && s1 <= 20;
    //@ assert s1 + c >= 3 && s1 + c <= 30;
    s2 = s1 + c;
    
    //@ assert s2 >= 3 && s2 <= 30;
    return s2;
}
