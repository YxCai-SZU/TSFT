#include <stdbool.h>

/*@
    predicate is_valid_range(integer k, integer x) =
        1 <= k <= 100 && 1 <= x <= 100000;

    logic integer calculate_product(integer k) = 500 * k;

    predicate product_ge_x(integer k, integer x) =
        calculate_product(k) >= x;
*/

/*@
    requires is_valid_range(k, x);
    ensures \result == true <==> product_ge_x(k, x);
    assigns \nothing;
*/
bool func(long k, long x)
{
    // Variable declarations at top of scope
    long product;
    bool result;

    //@ assert 1 <= k <= 100 && 1 <= x <= 100000;
    
    //@ assert 500 * k <= 500 * 100;
    
    product = 500 * k;
    
    //@ assert product == 500 * k;
    
    if (product >= x) {
        //@ assert product_ge_x(k, x);
        result = true;
    } else {
        //@ assert !product_ge_x(k, x);
        result = false;
    }
    
    return result;
}
