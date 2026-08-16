#include <limits.h>

/*@
    predicate a_in_range(integer a) = 2 <= a <= 100;
    predicate b_in_range(integer b) = 2 <= b <= 100;
    predicate both_in_range(integer a, integer b) = a_in_range(a) && b_in_range(b);
    
    logic integer final_expr(integer a, integer b) = (a * b) - (a + b - 1);
    
    lemma bounds_lemma: \forall integer a, b; both_in_range(a, b) ==> final_expr(a, b) >= 0;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures \result == final_expr(a, b);
    assigns \nothing;
*/
int func(int a, int b) {
    // Variable declarations at top
    int res;
    
    //@ assert 2 <= a <= 100;
    //@ assert 2 <= b <= 100;
    
    //@ assert 2 * 2 <= a * b <= 100 * 100;
    //@ assert 2 + 2 - 1 <= a + b - 1 <= 100 + 100 - 1;
    
    //@ assert final_expr(a, b) >= 0;
    
    res = (a * b) - (a + b - 1);
    //@ assert res == final_expr(a, b);
    
    return res;
}
