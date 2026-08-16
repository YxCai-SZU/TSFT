#include <stdbool.h>

/*@
    predicate is_valid_input(integer a, integer b) =
        (a == 1 && b == 1) ||
        (a == 1 && b == 2) ||
        (a == 2 && b == 1) ||
        (a == 2 && b == 2);

    predicate matches_output(integer a, integer b, integer res) =
        (a == 1 && b == 1 && res == 0) ||
        (a == 1 && b == 2 && res == 1) ||
        (a == 2 && b == 1 && res == 1) ||
        (a == 2 && b == 2 && res == 0);
*/

/*@
    requires is_valid_input(a, b);
    assigns \nothing;
    ensures matches_output(a, b, \result);
*/
int func(int a, int b)
{
    int res;

    //@ assert is_valid_input(a, b);
    
    if (a == b)
    {
        res = 0;
    }
    else
    {
        //@ assert (a == 1 && b == 2) || (a == 2 && b == 1);
        res = 1;
    }
    
    //@ assert matches_output(a, b, res);
    return res;
}
