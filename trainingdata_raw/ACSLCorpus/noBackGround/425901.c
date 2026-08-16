#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= 1;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    int64_t train;
    int64_t bus;
    int64_t result;
    
    //@ assert ((a) * (b)) <= 10000 * 10000;
    train = a * b;
    
    //@ assert ((c) * (d)) <= 10000 * 10000;
    bus = c * d;
    
    if (train < bus) {
        //@ assert ((a) * (b)) >= 1;
        result = train;
    } else {
        //@ assert ((c) * (d)) >= 1;
        result = bus;
    }
    
    return result;
}
