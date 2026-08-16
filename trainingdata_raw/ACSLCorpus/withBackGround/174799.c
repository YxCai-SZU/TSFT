#include <stdbool.h>

/*@
    predicate bounds(int v) = 1 <= v <= 100;
    predicate valid_inputs(int a, int b, int c) = 
        bounds(a) && bounds(b) && bounds(c);
*/

/*@
    requires valid_inputs(a, b, c);
    ensures \result == (a > c + b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert bounds(a);
    //@ assert bounds(b);
    //@ assert bounds(c);
    return a > c + b;
}
