#include <stdbool.h>

/*@
    predicate is_mod(integer n, integer a, integer mo) =
        mo == n % 500 && mo <= a;
*/

/*@
    logic integer compute_mod(integer n) = n % 500;
*/

/*@
    lemma mod_bound:
        \forall integer n, mo;
        1 <= n <= 10000 && mo == n % 500 ==> 0 <= mo <= 499;
*/

/*@
    requires 1 <= n <= 10000;
    requires 0 <= a <= 1000;
    ensures \result == (n % 500 <= a);
*/
bool func(unsigned int n, unsigned int a)
{
    unsigned int mo;
    bool result;

    mo = n % 500;
    //@ assert mo == n % 500;

    if (mo <= a)
    {
        //@ assert mo <= a;
        result = true;
    }
    else
    {
        //@ assert !(mo <= a);
        result = false;
    }

    return result;
}
