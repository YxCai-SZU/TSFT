#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 20;
    predicate b_in_range(integer b) = 1 <= b <= 20;
    predicate both_small(integer a, integer b) = a < 10 && b < 10;
    predicate result_small(integer a, integer b, integer r) = both_small(a, b) ==> r == a * b;
    predicate result_large(integer a, integer b, integer r) = !both_small(a, b) ==> r == -1;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures result_small(a, b, \result) && result_large(a, b, \result);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t result;
    //@ assert 1 <= a && a <= 20;
    //@ assert 1 <= b && b <= 20;
    //@ assert a * b <= 20 * 20;
    
    if (a < 10 && b < 10)
    {
        result = a * b;
    }
    else
    {
        result = -1;
    }
    
    //@ assert (a < 10 && b < 10) ==> result == a * b;
    //@ assert !(a < 10 && b < 10) ==> result == -1;
    
    return result;
}
