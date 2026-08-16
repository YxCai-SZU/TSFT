#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b));
    ensures \result >= ((c) * (d));
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long ab;
    long cd;
    long result;
    
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    //@ assert 1 <= ((a) * (b)) <= 10000 * 10000;
    ab = a * b;
    
    //@ assert 1 <= ((c) * (d)) <= 10000 * 10000;
    cd = c * d;
    
    if (ab > cd)
    {
        //@ assert ab >= ((a) * (b));
        //@ assert ab >= ((c) * (d));
        result = ab;
    }
    else
    {
        //@ assert cd >= ((a) * (b));
        //@ assert cd >= ((c) * (d));
        result = cd;
    }
    
    return result;
}
