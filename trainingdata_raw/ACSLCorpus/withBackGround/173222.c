#include <limits.h>

/*@
    predicate is_valid_params(integer a, integer b) =
        a >= 1 && a <= 100 &&
        b >= 1 && b <= 100;
*/

/*@
    logic integer square(integer x) = x * x;
*/

/*@
    lemma square_test:
        square(10) == 100;
*/

/*@
    requires is_valid_params(a, b);
    ensures \result == a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    
    return a * b;
}

/*@
    requires 0 <= x && x <= 100;
    ensures \result == square(x);
    assigns \nothing;
*/
int caller(int x)
{
    //@ assert 0 <= x && x <= 100;
    return x * x;
}
