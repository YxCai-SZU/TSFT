#include <stdbool.h>

/*@ predicate two_equal_one_different(integer a, integer b, integer c) =
      (a == b && a != c) || (a == c && a != b) || (b == c && a != b);
*/

/*@
  requires 1 <= a <= 9;
  requires 1 <= b <= 9;
  requires 1 <= c <= 9;
  ensures \result == true <==> two_equal_one_different(a, b, c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;

    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;

    if (a == b && a != c)
    {
        //@ assert a == b && a != c;
        result = true;
    }
    else if (a == c && a != b)
    {
        //@ assert a == c && a != b;
        result = true;
    }
    else if (b == c && a != b)
    {
        //@ assert b == c && a != b;
        result = true;
    }
    else
    {
        //@ assert !(a == b && a != c) && !(a == c && a != b) && !(b == c && a != b);
        result = false;
    }

    //@ assert result == true <==> two_equal_one_different(a, b, c);
    return result;
}
