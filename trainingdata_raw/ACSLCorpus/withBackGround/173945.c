#include <stdint.h>

/*@
    predicate is_in_range(integer a) = 1 <= a && a <= 10;
    
    logic integer compute_result(integer a) = a + a * a + a * a * a;
*/

/*@
    requires is_in_range(a);
    ensures \result == compute_result(a);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    int64_t a_1;
    int64_t a_2;
    int64_t a_3;
    int64_t ans;
    
    a_1 = a;
    
    //@ assert a * a >= 1 * 1 && a * a <= 10 * 10;
    a_2 = a * a;
    
    //@ assert a * a * a >= 1 * 1 * 1 && a * a * a <= 10 * 10 * 10;
    a_3 = a * a * a;
    
    ans = a_1 + a_2 + a_3;
    return ans;
}
