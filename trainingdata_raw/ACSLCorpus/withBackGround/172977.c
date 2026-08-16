#include <stdbool.h>

/*@ predicate is_ordered(integer a, integer b, integer c) =
      a < b && b < c;
*/

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  ensures \result == (a < b && b < c);
*/
bool func(int a, int b, int c)
{
    bool state = false;

    if (a < b)
    {
        if (b < c)
        {
            state = true;
        }
    }

    //@ assert state == (a < b && b < c);
    return state;
}
