#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a && a <= 100 && 1 <= b && b <= 100;

    logic integer compute_result(integer a, integer b) =
        (a * 2 * 3) + (b * 1);

    lemma no_overflow:
        \forall integer a; 1 <= a && a <= 100 ==> 1 <= a * 2 * 3 && a * 2 * 3 <= 100 * 2 * 3;
*/

/*@
    requires valid_range(a, b);
    ensures \result == compute_result(a, b);
*/
int func(int a, int b)
{
    int ans;
    
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= a * 2 * 3 && a * 2 * 3 <= 100 * 2 * 3;
    
    ans = (a * 2 * 3) + (b * 1);
    //@ assert ans == compute_result(a, b);
    
    return ans;
}
