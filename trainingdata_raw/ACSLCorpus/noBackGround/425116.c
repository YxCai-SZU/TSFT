#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result == (((n) % 1000 == 0) ? 0 : (1000 - ((n) % 1000)));
    ensures \result <= 1000;
    ensures (n % 1000 == 0) ==> \result == 0;
    ensures (n % 1000 != 0) ==> \result == 1000 - (n % 1000);
*/
size_t func(size_t n)
{
    size_t change;
    size_t r;
    
    //@ assert (1 <= (n) && (n) <= 100000);
    
    if (n % 1000 == 0)
    {
        change = 0;
        //@ assert change == 0;
    }
    else
    {
        r = n % 1000;
        //@ assert n % 1000 != 0;
        change = 1000 - r;
        //@ assert change == 1000 - (n % 1000);
    }
    
    //@ assert change == (((n) % 1000 == 0) ? 0 : (1000 - ((n) % 1000)));
    //@ assert change <= 1000;
    return change;
}
