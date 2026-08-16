#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && 
             (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures 1 <= \result <= 100000000;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    int64_t sa = a * b;
    int64_t sc = c * d;
    
    //@ assert sa == ((a) * (b));
    //@ assert sc == ((c) * (d));
    
    //@ assert 1 <= sa <= 100000000;
    //@ assert 1 <= sc <= 100000000;
    
    int64_t result;
    if (sa > sc) {
        result = sa;
        //@ assert result == ((a) * (b));
    } else {
        result = sc;
        //@ assert result == ((c) * (d));
    }
    
    //@ assert result == ((a) * (b)) || result == ((c) * (d));
    //@ assert 1 <= result <= 100000000;
    
    return result;
}
