#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n && n <= 10000 && 0 <= m && m <= 1000;

    logic integer mod_500(integer n) = n % 500;

    lemma mod_bound: \forall integer n; 1 <= n <= 10000 ==> 0 <= mod_500(n) <= 10000;
*/

/*@
    requires valid_params(n, m);
    ensures \result == (n % 500 <= m);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    // Variable declarations at top of scope
    bool res;
    unsigned int mod_result;

    //@ assert 1 <= n && n <= 10000;
    mod_result = n % 500;
    
    //@ assert 0 <= mod_result && mod_result <= 10000;
    res = (mod_result <= m);
    
    //@ assert res == (n % 500 <= m);
    return res;
}
