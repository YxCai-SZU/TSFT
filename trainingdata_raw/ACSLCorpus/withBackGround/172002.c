#include <stdbool.h>

/*@ predicate diff_equal(integer a, integer b, integer c) =
      b - a == c - b;
*/

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  ensures \result == (b - a == c - b);
  assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool result = false;
    int diff1 = 0;
    int diff2 = 0;

    diff1 = b - a;
    diff2 = c - b;

    if (diff1 == diff2)
    {
        result = true;
    }

    //@ assert result == (b - a == c - b);

    return result;
}
