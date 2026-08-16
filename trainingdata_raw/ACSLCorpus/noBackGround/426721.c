#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 100) && (0 <= (b) && (b) <= 100) && (0 <= (c) && (c) <= 100);
    ensures \result == (((a) * (b)) * (c));
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c)
{
    //@ assert (0 <= (a) && (a) <= 100);
    //@ assert (0 <= (b) && (b) <= 100);
    //@ assert (0 <= (c) && (c) <= 100);
    
    //@ assert 0 <= a * b && a * b <= 10000;
    //@ assert 0 <= (a * b) * c && (a * b) * c <= 1000000;
    
    return (a * b) * c;
}
