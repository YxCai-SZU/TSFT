#include <stdbool.h>

/*@
    predicate in_range(integer a) = -100 <= a <= 100;
    
    predicate condition_zero(integer a, integer b, integer c) = 
        a <= c && c <= b;
    
    predicate condition_two(integer a, integer b, integer c) = 
        c < a || c > b;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == 0 || \result == 2;
    ensures \result == 0 ==> condition_zero(a, b, c);
    ensures \result == 2 ==> condition_two(a, b, c);
*/
int count_noderoot(int a, int b, int c)
{
    //@ assert in_range(a) && in_range(b) && in_range(c);
    
    if (a <= c && c <= b)
    {
        //@ assert condition_zero(a, b, c);
        return 0;
    }
    else
    {
        //@ assert condition_two(a, b, c);
        return 2;
    }
}
