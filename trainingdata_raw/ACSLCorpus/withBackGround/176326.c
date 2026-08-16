#include <stddef.h>

/*@
    predicate valid_input(integer n) = 1 <= n && n <= 10000;

    logic integer ceiling_div_1000(integer n) = (n + 999) / 1000;

    logic integer compute_result(integer n) = 
        ceiling_div_1000(n) * 1000 - n;
*/

/*@
    requires valid_input(n);
    ensures \result == compute_result(n);
    assigns \nothing;
*/
size_t func(size_t n) {
    size_t num;
    size_t result;

    //@ assert valid_input(n);
    
    num = (n + 999) / 1000;
    
    //@ assert num == ceiling_div_1000(n);
    
    result = num * 1000 - n;
    
    //@ assert result == compute_result(n);
    
    return result;
}
