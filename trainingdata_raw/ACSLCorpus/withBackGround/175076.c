#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r && r <= 100;
    
    logic integer area_formula(integer r) = 3 * r * r;
    
    lemma no_overflow1: \forall integer r; valid_range(r) ==> 3 * r <= 300;
    lemma no_overflow2: \forall integer r; valid_range(r) ==> 3 * r * r <= 30000;
*/

/*@
    requires valid_range(r);
    ensures \result == area_formula(r);
    ensures \result == 3 * r * r;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top
    int64_t area;
    
    //@ assert valid_range(r);
    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r <= 30000;
    
    area = 3 * r * r;
    
    //@ assert area == area_formula(r);
    //@ assert area == 3 * r * r;
    
    return area;
}
