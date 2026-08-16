#include <stdbool.h>

/*@
    predicate is_even_pre(integer n) = n < 2 || n > 2;

    predicate is_even_result(integer n, bool ret) = ret == (n % 2 == 0);
*/

/*@
    requires is_even_pre(n);
    ensures is_even_result(n, \result);
    assigns \nothing;
*/
bool is_even(unsigned int n)
{
    //@ assert n < 2 || n > 2;
    
    bool ret;
    ret = (n % 2 == 0);
    
    //@ assert ret == (n % 2 == 0);
    return ret;
}
