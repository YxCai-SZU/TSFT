#include <stddef.h>

/*@ predicate is_valid_range(integer r) = 1 <= r && r <= 100; */

/*@ logic integer square(integer r) = r * r; */

/*@ lemma square_bounds: 
      \forall integer r; is_valid_range(r) ==> square(r) <= 10000; */

/*@ requires is_valid_range(r);
    ensures \result == square(r);
    assigns \nothing;
 */
size_t func(size_t r)
{
    // Variable declarations at top of scope
    size_t res;

    //@ assert 1 <= r && r <= 100;
    //@ assert r * r <= 10000;
    
    res = r * r;
    
    //@ assert res == square(r);
    return res;
}
