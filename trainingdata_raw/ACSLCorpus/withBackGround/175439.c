#include <stdbool.h>

/*@ predicate in_range(integer v) = 0 <= v <= 100; */

/*@
    requires in_range(a);
    requires in_range(b);
    requires in_range(x);
    ensures \result == (x >= a && x <= a + b);
*/
bool func(int a, int b, int x)
{
    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(x);
    return x >= a && x <= (a + b);
}
