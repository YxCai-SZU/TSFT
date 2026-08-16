#include <stdbool.h>

/*@ predicate is_odd(integer n) = n % 2 != 0; */

/*@
    requires n < 0x80000000;
    ensures \result == (n % 2 != 0);
    assigns \nothing;
*/
bool is_odd(unsigned int n)
{
    // Variable declarations at top of scope
    bool ret;

    //@ assert n < 0x80000000;
    
    ret = (n % 2 != 0);
    
    //@ assert ret == (n % 2 != 0);
    return ret;
}
