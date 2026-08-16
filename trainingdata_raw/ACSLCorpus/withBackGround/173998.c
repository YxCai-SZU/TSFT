#include <stdbool.h>

/*@
    predicate is_even_pred(integer n) = (n & 1) == 0;
*/

/*@
    requires n <= 4294967295;
    ensures \result == ((n & 1) == 0);
    assigns \nothing;
*/
bool is_even(unsigned int n)
{
    //@ assert n <= 4294967295;
    bool ret;
    ret = (n & 1) == 0;
    //@ assert ret == ((n & 1) == 0);
    return ret;
}
