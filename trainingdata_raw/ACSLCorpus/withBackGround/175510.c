#include <stdbool.h>

/*@
    predicate is_modulo(integer n, integer a, integer r) =
        r == n % 500;
*/

/*@
    lemma modulo_range:
        \forall integer n, integer a;
            1 <= n <= 10000 && 0 <= a <= 1000 ==>
                \let r = n % 500;
                0 <= r < 500;
*/

/*@
    requires 1 <= n <= 10000;
    requires 0 <= a <= 1000;
    ensures \result == (n % 500 <= a);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int a) {
    unsigned int r;
    bool result;
    
    r = n % 500;
    
    //@ assert is_modulo(n, a, r);
    
    result = (r <= a);
    
    //@ assert result == (n % 500 <= a);
    
    return result;
}
