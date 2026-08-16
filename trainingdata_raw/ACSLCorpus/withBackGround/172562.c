#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100000;
*/

/*@
    requires is_valid_n(n);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    uint32_t tmp;
    int32_t res;

    //@ assert is_valid_n(n);
    tmp = n % 100 * 21;
    
    if (tmp >= n) {
        res = 1;
    } else {
        //@ assert tmp < n;
        res = 0;
    }
    
    //@ assert res == 0 || res == 1;
    return res;
}
