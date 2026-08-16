#include <limits.h>

/*@
    predicate is_max(integer val, integer a, integer b, integer c, integer d) =
        (val == a || val == b || val == c || val == d) &&
        val >= a && val >= b && val >= c && val >= d;
*/

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    requires -100 <= d <= 100;
    ensures is_max(\result, a, b, c, d);
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max1 = a;
    int max2 = c;
    
    //@ assert max1 >= a;
    
    if (b > max1)
    {
        max1 = b;
    }
    
    //@ assert max1 >= a && max1 >= b;
    
    if (d > max2)
    {
        max2 = d;
    }
    
    //@ assert max2 >= c && max2 >= d;
    
    //@ assert max1 >= a && max1 >= b;
    //@ assert max2 >= c && max2 >= d;
    
    return (max1 > max2) ? max1 : max2;
}
