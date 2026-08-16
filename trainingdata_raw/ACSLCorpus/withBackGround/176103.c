#include <stdbool.h>

/*@
    predicate is_triangle(integer a, integer b, integer c) =
        (a + b) > c || (a + c) > b || (b + c) > a;
 */

/*@
    requires 1 <= a <= 1000000000;
    requires 1 <= b <= 1000000000;
    requires 1 <= c <= 1000000000;
    ensures \result == true <==> is_triangle(a, b, c);
 */
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    //@ assert 1 <= a <= 1000000000;
    //@ assert 1 <= b <= 1000000000;
    //@ assert 1 <= c <= 1000000000;
    
    if (a + b > c || a + c > b || b + c > a)
    {
        result = true;
        //@ assert is_triangle(a, b, c);
    }
    else
    {
        //@ assert (a + b) <= c && (a + c) <= b && (b + c) <= a;
        result = false;
    }
    
    return result;
}
