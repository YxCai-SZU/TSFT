#include <stdbool.h>

/*@ predicate can_communicate_pre(integer a, integer b, integer c, integer d) =
      1 <= a && a <= 10000 &&
      1 <= b && b <= 10000 &&
      1 <= c && c <= 10000 &&
      1 <= d && d <= 10000;
*/

/*@ logic integer abs_diff(integer a, integer d) =
      a > d ? a - d : d - a;
*/

/*@ lemma diff_definition:
      \forall integer a, d;
      abs_diff(a, d) == (a - d > 0 ? a - d : d - a);
*/

/*@ requires can_communicate_pre(a, b, c, d);
    ensures \result == (abs_diff(a, d) <= c);
*/
bool can_communicate(long a, long b, long c, long d)
{
    long diff;
    //@ assert can_communicate_pre(a, b, c, d);
    
    if (a > d) {
        diff = a - d;
    } else {
        diff = d - a;
    }
    //@ assert diff == abs_diff(a, d);
    
    return diff <= c;
}
