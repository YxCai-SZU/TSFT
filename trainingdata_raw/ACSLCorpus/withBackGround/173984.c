#include <stdint.h>

/*@
    predicate valid_range(integer a) = 1 <= a <= 100;
    
    logic integer multiply(integer a, integer b) = a * b;
    
    lemma multiplication_bounds:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> 
            1 <= multiply(a, b) <= 10000;
*/

/*@
    requires valid_range(a) && valid_range(b);
    requires a == (int64_t)a && b == (int64_t)b;
    ensures \result == multiply(a, b);
    ensures 1 <= \result <= 10000;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t ans;
    
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert 1 <= multiply(a, b) <= 10000;
    
    ans = a * b;
    return ans;
}
