#include <stdbool.h>

/*@
    predicate is_valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer compute_result(integer a, integer b) =
        a < b * 2 ? 0 : a - b * 2;
*/

/*@
    requires is_valid_range(a, b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    int ans;
    //@ assert is_valid_range(a, b);
    
    if (a < b * 2) {
        ans = 0;
        //@ assert ans == 0;
    } else {
        ans = a - b * 2;
        //@ assert ans == a - b * 2;
    }
    
    //@ assert ans == compute_result(a, b);
    return ans;
}
