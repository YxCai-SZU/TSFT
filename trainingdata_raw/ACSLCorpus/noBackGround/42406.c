#include <stdbool.h>

/*@
  requires a != b;
  requires (-100 <= (a) <= 100);
  requires (-100 <= (b) <= 100);
  requires (-100 <= (c) <= 100);
  ensures \result == ((a < b && c > a && c < b) || (a > b && c > b && c < a));
*/
bool func(long a, long b, long c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    //@ assert (-100 <= (c) <= 100);
    //@ assert a != b;

    if ((a < b && c > a && c < b) || (a > b && c > b && c < a)) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
