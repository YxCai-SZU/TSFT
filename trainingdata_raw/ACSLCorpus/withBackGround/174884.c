#include <stdint.h>

/*@
    predicate r_in_range(integer r) = 1 <= r <= 100;
*/

/*@
    requires r_in_range(r);
    ensures \result == r * 6;
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert r * 6 <= 100 * 6;
    //@ assert r * 6 >= 1 * 6;
    
    result = r * 6;
    return result;
}

int main(void)
{
    return 0;
}
