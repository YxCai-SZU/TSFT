#include <stdint.h>

/*@
    predicate valid_range(integer v) = 0 <= v <= 10;

    logic integer compute_result(integer x, integer y, integer z) =
        x * y * z + x * y * z + y * z;

    lemma product_bound1:
        \forall integer x, y;
        valid_range(x) && valid_range(y) ==> 0 <= x * y <= 100;

    lemma product_bound2:
        \forall integer x, y, z;
        valid_range(x) && valid_range(y) && valid_range(z) ==> 0 <= x * y * z <= 1000;

    lemma sum_bound1:
        \forall integer x, y, z;
        valid_range(x) && valid_range(y) && valid_range(z) ==> 0 <= x * y * z + x * y * z <= 2000;

    lemma sum_bound2:
        \forall integer x, y, z;
        valid_range(x) && valid_range(y) && valid_range(z) ==> 0 <= x * y * z + x * y * z + y * z <= 2100;
*/

/*@
    requires 0 <= x <= 10;
    requires 0 <= y <= 10;
    requires 0 <= z <= 10;
    ensures \result == compute_result(x, y, z);
    assigns \nothing;
*/
int64_t func(int64_t x, int64_t y, int64_t z)
{
    // Variable declarations at top of scope
    int64_t result;

    //@ assert valid_range(x);
    //@ assert valid_range(y);
    //@ assert valid_range(z);
    
    //@ assert 0 <= x * y <= 100;
    //@ assert 0 <= x * y * z <= 1000;
    //@ assert 0 <= x * y * z + x * y * z <= 2000;
    //@ assert 0 <= x * y * z + x * y * z + y * z <= 2100;

    result = x * y * z + x * y * z + y * z;
    
    //@ assert result == compute_result(x, y, z);
    return result;
}
