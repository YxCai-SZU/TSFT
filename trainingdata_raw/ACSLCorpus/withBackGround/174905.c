#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b, integer c) =
        1 <= a && a <= 500 &&
        1 <= b && b <= 500 &&
        1 <= c && c <= 1000;

    logic integer sum(integer a, integer b) = a + b;
*/

/*@
    requires valid_range(a, b, c);
    ensures \result == (sum(a, b) >= c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert 1 <= a && a <= 500;
    //@ assert 1 <= b && b <= 500;
    //@ assert 1 <= c && c <= 1000;
    
    return (a + b) >= c;
}
