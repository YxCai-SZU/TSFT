#include <limits.h>

/*@
    predicate in_range(integer x) = -100 <= x <= 100;
    
    logic integer max_of_four(integer a, integer b, integer c, integer d) =
        (a + c) >= (a + d) && (a + c) >= (b + c) && (a + c) >= (b + d) ? a + c :
        (a + d) >= (b + c) && (a + d) >= (b + d) ? a + d :
        (b + c) >= (b + d) ? b + c : b + d;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == max_of_four(a, b, c, d);
    ensures \result >= a + c && \result >= a + d && \result >= b + c && \result >= b + d;
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
*/
int func(int a, int b, int c, int d)
{
    int max_value;
    int max_a;
    int max_c;
    
    max_value = a + c;
    //@ assert max_value == a + c;
    
    if (a + d > max_value)
    {
        max_value = a + d;
        //@ assert max_value == a + d;
    }
    
    if (b + c > max_value)
    {
        max_value = b + c;
        //@ assert max_value == b + c;
    }
    
    if (b + d > max_value)
    {
        max_value = b + d;
        //@ assert max_value == b + d;
    }
    
    max_a = a;
    if (b > max_a)
    {
        max_a = b;
    }
    //@ assert max_a >= a && max_a >= b;
    
    max_c = c;
    if (d > max_c)
    {
        max_c = d;
    }
    //@ assert max_c >= c && max_c >= d;
    
    //@ assert max_a + max_c >= a + c;
    //@ assert max_a + max_c >= a + d;
    //@ assert max_a + max_c >= b + c;
    //@ assert max_a + max_c >= b + d;
    
    return max_a + max_c;
}
