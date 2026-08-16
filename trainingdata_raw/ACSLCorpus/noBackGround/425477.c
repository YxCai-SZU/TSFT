#include <stddef.h>

/*@
    requires (2 <= (n) && (n) <= 100 &&
        2 <= (m) && (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
size_t func(size_t n, size_t m)
{
    //@ assert n > 1;
    //@ assert m > 1;
    //@ assert n - 1 >= 1;
    //@ assert m - 1 >= 1;
    //@ assert (n - 1) * (m - 1) <= 9801;
    
    return (n - 1) * (m - 1);
}
