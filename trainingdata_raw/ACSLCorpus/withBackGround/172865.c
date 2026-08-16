#include <stddef.h>

/*@
    predicate is_valid_n(integer n) =
        1 <= n && n <= 10000;

    logic integer remainder(integer n) =
        n % 1000;

    logic integer compute_res(integer n) =
        remainder(n) == 0 ? 0 : 1000 - remainder(n);
*/

/*@
    requires is_valid_n(n);
    ensures \result < 1000;
    ensures \result >= 0;
    ensures n % 1000 == 0 ==> \result == 0;
    ensures n % 1000 != 0 ==> \result == 1000 - n % 1000;
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t mo;
    size_t res;

    mo = n % 1000;
    //@ assert mo == remainder(n);
    
    if (mo == 0)
    {
        res = 0;
        //@ assert res == compute_res(n);
        return res;
    }
    else
    {
        //@ assert mo != 0;
        res = 1000 - mo;
        //@ assert res == compute_res(n);
        return res;
    }
}
