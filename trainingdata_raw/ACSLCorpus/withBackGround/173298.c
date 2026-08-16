#include <stdbool.h>

/*@ predicate condition_holds(integer n) =
      n % 100 < 6 || n % 100 >= 90;
*/

/*@
  requires 1 <= n <= 10000;
  ensures \result == (n % 100 < 6 || n % 100 >= 90);
*/
bool func(unsigned int n)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int remainder;

    remainder = n % 100;

    if (remainder < 6 || remainder >= 90)
    {
        //@ assert remainder < 6 || remainder >= 90;
        result = true;
    }
    else
    {
        //@ assert !(remainder < 6 || remainder >= 90);
        result = false;
    }

    return result;
}
