#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 500;
    predicate b_in_range(integer b) = 1 <= b <= 500;
    predicate c_in_range(integer c) = 1 <= c <= 1000;
*/

/*@
    requires a_in_range(a);
    requires b_in_range(b);
    requires c_in_range(c);
    ensures \result == (a + b >= c);
*/
bool func(int a, int b, int c)
{
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert c_in_range(c);
    
    return a + b >= c;
}
