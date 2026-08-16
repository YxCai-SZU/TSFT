#include <stddef.h>

/*@
    requires (0 <= (n) <= 1);
    ensures (n == 0 ==> \result == 1) && (n == 1 ==> \result == 0);
    assigns \nothing;
*/
size_t func(size_t n)
{
    //@ assert (0 <= (n) <= 1);
    
    if (n == 1) {
        //@ assert n == 1;
        return 0;
    } else {
        //@ assert n == 0;
        return 1;
    }
}
