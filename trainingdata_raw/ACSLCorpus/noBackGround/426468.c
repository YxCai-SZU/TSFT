#include <stddef.h>

/*@
    requires (2 <= (k) <= 100);
    ensures \result == ((((k)) / 2) * ((((k)) + 1) / 2));
    assigns \nothing;
*/
size_t func(size_t k)
{
    size_t n;
    size_t m;
    size_t res;

    //@ assert (2 <= (k) <= 100);
    
    n = k / 2;
    m = (k + 1) / 2;
    
    //@ assert n == ((k) / 2);
    //@ assert m == (((k) + 1) / 2);
    
    //@ assert n >= 1;
    //@ assert m >= 1;
    
    //@ assert n * m <= 50 * 50;
    
    res = n * m;
    
    //@ assert res == ((((k)) / 2) * ((((k)) + 1) / 2));
    return res;
}
