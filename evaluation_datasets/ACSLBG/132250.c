#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer x) =
        1 <= n && n <= 100 &&
        1 <= x && x <= 100000;

    logic integer scaled_n(integer n) = n * 500;

    lemma scaled_n_bounds:
        \forall integer n; 1 <= n <= 100 ==> 500 <= scaled_n(n) <= 50000;
*/


bool func(unsigned long n, unsigned long x)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= x && x <= 100000;
    
    //@ assert n * 500 <= 100 * 500;
    //@ assert n * 500 >= 1 * 500;

    if (n * 500 >= x) {
        //@ assert n * 500 >= x;
        result = true;
    } else {
        //@ assert !(n * 500 >= x);
        result = false;
    }

    return result;
}
