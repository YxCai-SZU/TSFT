#include <stdbool.h>

/*@
    predicate is_between(integer a, integer b, integer c) =
        (a < c && c < b) || (a > c && c > b);
*/

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    requires a != b && b != c && a != c;
    ensures \result == true <==> is_between(a, b, c);
*/
bool func(int a, int b, int c)
{
    //@ assert a != b && b != c && a != c;
    
    if ((a < c && c < b) || (a > c && c > b))
    {
        return true;
    }
    else
    {
        return false;
    }
}
