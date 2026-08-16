#include <stddef.h>

/*@
    requires (1 <= (n) <= 1000000);
    ensures \result == (((n) / 2) + ((n) % 2));
    ensures (1 <= (\result) <= 500000);
*/
size_t func(size_t n)
{
    // Variable declarations at top of scope
    size_t res;

    //@ assert n / 2 <= 500000;
    //@ assert n % 2 <= 1;
    //@ assert (n / 2) + (n % 2) <= 500001;

    res = (n / 2) + (n % 2);
    
    //@ assert res == (n / 2) + (n % 2);
    //@ assert res >= 1;
    //@ assert res <= 500000;
    
    return res;
}
