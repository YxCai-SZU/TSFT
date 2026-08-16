#include <stdint.h>

/*@
    predicate valid_range(integer a) = 1 <= a <= 100;

    lemma lemma_1: \forall integer a; valid_range(a) ==> a * a <= 10000;
    lemma lemma_2: \forall integer a; valid_range(a) ==> a * a >= 1;
*/

/*@
    requires valid_range(a);
    ensures \result == a * a;
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at top of scope
    int64_t ans;

    //@ assert valid_range(a);
    //@ assert a * a <= 10000;
    //@ assert a * a >= 1;
    
    ans = a * a;
    return ans;
}
