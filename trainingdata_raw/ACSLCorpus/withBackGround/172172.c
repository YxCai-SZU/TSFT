#include <stdint.h>

/*@
    predicate valid_input(integer r, integer g) =
        0 <= r <= 4500 && 0 <= g <= 4500;
    
    logic integer compute_result(integer r, integer g) =
        2 * g - r;
*/

/*@
    requires valid_input(r, g);
    ensures \result == compute_result(r, g);
    assigns \nothing;
*/
int32_t func(int32_t r, int32_t g)
{
    // Variable declarations at scope top
    int32_t res;
    
    //@ assert valid_input(r, g);
    
    res = 2 * g - r;
    
    //@ assert res == compute_result(r, g);
    
    return res;
}

int main(void)
{
    return 0;
}
