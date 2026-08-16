#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 5000;
    predicate b_in_range(integer b) = 1 <= b && b <= 5000;
    predicate c_in_range(integer c) = 1 <= c && c <= 10000;
    predicate sum_in_range(integer a, integer b) = a + b <= 10000;
*/

/*@
    lemma sum_bound: \forall integer a, b; a_in_range(a) && b_in_range(b) ==> sum_in_range(a, b);
*/

/*@
    requires a_in_range(a);
    requires b_in_range(b);
    requires c_in_range(c);
    ensures \result == (a + b >= c);
*/
bool func(int a, int b, int c)
{
    bool ans;
    
    //@ assert sum_in_range(a, b);
    
    if (a + b >= c) {
        ans = true;
    } else {
        ans = false;
    }
    
    return ans;
}
