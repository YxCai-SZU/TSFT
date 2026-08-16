#include <stdbool.h>

/*@
    requires n >= 0;
    ensures \result == (n % 2 != 0);
    assigns \nothing;
*/
bool is_odd(unsigned int n)
{
    //@ assert n >= 0 && n <= 4294967295;
    return n % 2 != 0;
}
