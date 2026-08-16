#include <stdbool.h>

/*@
    predicate is_between(integer a, integer c, integer b) =
        (a < c && c < b) || (a > c && c > b);
*/

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result == true <==> is_between(a, c, b);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    
    bool result;
    
    if ((a < c && c < b) || (a > c && c > b))
    {
        result = true;
    }
    else
    {
        result = false;
    }
    
    return result;
}
