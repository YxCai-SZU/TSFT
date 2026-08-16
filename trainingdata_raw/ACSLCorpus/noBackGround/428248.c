#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == (x >= 2000 || (((x) % 200) != 0 && ((x) / 200) >= ((x) % 200)));
    assigns \nothing;
*/
bool func(unsigned int x)
{
    unsigned int r;
    unsigned int q;

    //@ assert (1 <= (x) <= 100000);
    
    if (x >= 2000)
    {
        return true;
    }

    r = x % 200;
    q = x / 200;
    
    //@ assert q == ((x) / 200);
    //@ assert r == ((x) % 200);
    //@ assert 0 <= q <= 500;
    
    return (r != 0) && (q >= r);
}
