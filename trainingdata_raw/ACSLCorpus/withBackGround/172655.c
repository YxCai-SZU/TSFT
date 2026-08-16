#include <stddef.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 10000;

    logic integer modulo(integer n) = n % 1000;

    logic integer compute_result(integer n) = 
        modulo(n) == 0 ? 0 : 1000 - modulo(n);

    lemma modulo_equality:
        \forall integer n; is_valid_n(n) ==> 
        (1000 - (n % 1000)) == (1000 - modulo(n));
*/

/*@
    requires is_valid_n(n);
    ensures \result == compute_result(n);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t mo;
    size_t result;

    mo = n % 1000;
    
    if (mo == 0) {
        result = 0;
    } else {
        //@ assert 1000 - mo == 1000 - (n % 1000);
        result = 1000 - mo;
    }
    
    return result;
}
