#include <stdbool.h>

/*@ predicate in_range(integer v) = 0 <= v <= 100; */

/*@
  requires in_range(a) && in_range(b) && in_range(x);
  ensures \result == true <==> (x >= a && x <= a + b);
*/
bool func(long a, long b, long x)
{
    long max_val;
    long min_val;
    bool result;

    //@ assert a + b >= a;
    //@ assert a + b <= 200;

    if (a > x) {
        max_val = a;
    } else {
        max_val = x;
    }

    if (a + b < max_val) {
        min_val = a + b;
    } else {
        min_val = max_val;
    }

    if (x <= min_val && x >= a) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
