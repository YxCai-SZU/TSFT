#include <stdbool.h>

/*@
    predicate is_between(integer a, integer b, integer c) =
        (a < c && c < b) || (a > c && c > b);
 */

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    requires a != b;
    requires b != c;
    requires a != c;
    ensures \result == true <==> is_between(a, b, c);
 */
bool func(int a, int b, int c)
{
    bool result;
    //@ assert a != b && b != c && a != c;
    
    if ((a < c && c < b) || (a > c && c > b))
    {
        result = true;
        //@ assert is_between(a, b, c);
    }
    else
    {
        if (a < b)
        {
            if (c < a || c > b)
            {
                result = false;
                //@ assert !is_between(a, b, c);
            }
            else
            {
                result = true;
                //@ assert is_between(a, b, c);
            }
        }
        else
        {
            if (c < a || c > b)
            {
                result = false;
                //@ assert !is_between(a, b, c);
            }
            else
            {
                result = true;
                //@ assert is_between(a, b, c);
            }
        }
    }
    
    return result;
}
