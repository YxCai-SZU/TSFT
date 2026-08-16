#include <stdbool.h>

/*@
    predicate valid_array(int *a, integer len) =
        len == 3 &&
        \valid(a + (0 .. 2)) &&
        -100 <= a[0] <= 100 &&
        -100 <= a[1] <= 100 &&
        -100 <= a[2] <= 100;

    predicate condition_holds(int *a) =
        a[0] <= a[2] && a[2] <= a[1];
*/

/*@
    requires valid_array(a, 3);
    ensures \result == 1 <==> condition_holds(a);
    assigns \nothing;
*/
bool func(int *a)
{
    bool ans;
    ans = false;

    //@ assert valid_array(a, 3);
    
    if (a[0] <= a[2] && a[2] <= a[1])
    {
        ans = true;
    }

    //@ assert ans == 1 <==> condition_holds(a);
    
    return ans;
}
