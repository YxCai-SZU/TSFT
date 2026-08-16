#include <stdbool.h>

/*@
    predicate modulo_invariant(integer modulo, integer n) =
        0 <= modulo <= n &&
        modulo % 500 == n % 500;
*/

/*@
    requires 1 <= n <= 10000;
    requires 0 <= a <= 1000;
    ensures \result == (n % 500 <= a);
*/
bool func(long n, long a)
{
    long modulo = n;
    
    /*@
        loop invariant modulo_invariant(modulo, n);
        loop assigns modulo;
        loop variant modulo;
    */
    while (modulo >= 500)
    {
        modulo -= 500;
    }
    
    //@ assert modulo == n % 500;
    return modulo <= a;
}
