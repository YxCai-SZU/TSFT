#include <stdbool.h>

/*@ predicate condition_holds(integer a, integer b, integer c) =
      a + b + 1 >= c;
*/

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  ensures \result == true <==> condition_holds(a, b, c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int ab;
    bool ans;

    ab = a + b;
    ans = false;

    if (ab + 1 >= c)
    {
        ans = true;
    }

    //@ assert ans == true <==> ab + 1 >= c;

    return ans;
}
