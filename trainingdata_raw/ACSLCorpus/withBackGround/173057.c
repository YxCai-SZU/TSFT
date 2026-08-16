#include <limits.h>

/*@
    predicate is_less_than(integer a, integer b, integer c) =
        a < b && b < c;
*/

/*@
    requires a > INT_MIN && b > INT_MIN && c > INT_MIN;
    requires a < INT_MAX && b < INT_MAX && c < INT_MAX;
    ensures \result == 1 <==> is_less_than(a, b, c);
*/
int func(int a, int b, int c)
{
    int is_less;
    int tmp;

    // Check if `a` is less than `b`
    is_less = a < b;
    
    // Check if `b` is less than `c`
    tmp = b < c;
    is_less = is_less && tmp;
    
    //@ assert is_less == (a < b && b < c);
    
    return is_less;
}
