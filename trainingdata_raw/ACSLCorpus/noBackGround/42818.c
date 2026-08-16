#include <stdbool.h>

/*@
  requires (-100 <= (a) && (a) <= 100) && (-100 <= (b) && (b) <= 100) && (-100 <= (c) && (c) <= 100) && (-100 <= (d) && (d) <= 100);
  requires a <= b && c <= d;
  ensures \result == (b >= c && a <= d);
*/
bool func(long a, long b, long c, long d)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (-100 <= (a) && (a) <= 100);
    //@ assert (-100 <= (b) && (b) <= 100);
    //@ assert (-100 <= (c) && (c) <= 100);
    //@ assert (-100 <= (d) && (d) <= 100);

    result = (b >= c && a <= d);
    return result;
}
