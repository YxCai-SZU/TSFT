#include <stdbool.h>

/*@ predicate in_range(integer x) = 1 <= x <= 100; */

/*@
  requires in_range(a) && in_range(b) && in_range(c);
  ensures \result == (b - a == c - b);
  assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    return b - a == c - b;
}
