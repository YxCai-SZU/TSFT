#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 5000 &&
        1 <= (b) && (b) <= 5000 &&
        1 <= (c) && (c) <= 5000 &&
        1 <= (d) && (d) <= 5000);
    ensures \result >= 0;
    ensures (a + b + c <= d) ==> \result == a + b + c + d;
    ensures (a + b + c > d) ==> \result == b + c + d;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t x;
    //@ assert (1 <= (a) && (a) <= 5000 &&         1 <= (b) && (b) <= 5000 &&         1 <= (c) && (c) <= 5000 &&         1 <= (d) && (d) <= 5000);
    
    if (a + b + c <= d)
    {
        x = a + b + c + d;
        //@ assert x == a + b + c + d;
    }
    else
    {
        x = b + c + d;
        //@ assert x == b + c + d;
    }
    
    //@ assert x >= 0;
    return x;
}
