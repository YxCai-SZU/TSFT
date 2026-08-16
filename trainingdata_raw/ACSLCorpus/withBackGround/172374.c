#include <stdbool.h>

/*@
    predicate is_enough(integer k, integer x) =
        k * 500 >= x;
 */

/*@
    requires 1 <= k <= 100;
    requires 1 <= x <= 100000;
    ensures \result == true <==> k * 500 >= x;
    assigns \nothing;
 */
bool func(int k, int x)
{
    int k_value;
    bool is_enough;
    
    k_value = 500 * k;
    is_enough = false;
    
    //@ assert k_value == 500 * k;
    
    if (k_value >= x) {
        is_enough = true;
    }
    
    //@ assert is_enough == (k * 500 >= x);
    
    return is_enough;
}
