#include <stdbool.h>

/*@
    predicate is_modulo_result(integer n, integer a, integer mod_res) =
        mod_res == n % 500 && mod_res <= a;
*/

/*@
    requires 1 <= n && n <= 10000;
    requires 0 <= a && a <= 1000;
    ensures \result == (n % 500 <= a);
    assigns \nothing;
*/
bool func(unsigned long n, unsigned long a)
{
    unsigned long modulo_result;
    bool result;

    modulo_result = n % 500;
    //@ assert modulo_result == n % 500;
    
    result = (modulo_result <= a);
    return result;
}
