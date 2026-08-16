#include <stdbool.h>

/*@ predicate is_between(integer a, integer b, integer c) =
      (a < c && c < b) || (b < c && c < a);
*/

/*@
    requires 0 <= a && a <= 100;
    requires 0 <= b && b <= 100;
    requires 0 <= c && c <= 100;
    requires a != b && a != c && b != c;
    ensures \result == true <==> is_between(a, b, c);
*/
bool func(int a, int b, int c)
{
    bool result;
    //@ assert a != b && a != c && b != c;
    
    if ((a < c && c < b) || (b < c && c < a))
    {
        result = true;
        //@ assert is_between(a, b, c);
    }
    else
    {
        result = false;
        //@ assert !is_between(a, b, c);
    }
    
    return result;
}
