#include <stddef.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 10000;

    logic integer mod_100(integer n) = n % 100;

    logic integer compute_res(integer n) =
        mod_100(n) >= 13 ? 0 : 1000 - mod_100(n);
*/


size_t func(size_t n)
{
    size_t res;
    int mod_result;
    
    //@ assert is_valid_n(n);
    mod_result = n % 100;
    
    if (mod_result >= 13) {
        res = 0;
        //@ assert res == 0;
    } else {
        res = 1000 - mod_result;
        //@ assert res == 1000 - mod_result;
    }
    
    //@ assert (mod_result >= 13 ==> res == 0) && (mod_result < 13 ==> res == 1000 - mod_result);
    return res;
}
