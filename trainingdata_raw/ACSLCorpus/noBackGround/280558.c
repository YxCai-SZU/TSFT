#include <stddef.h>

/*@
    requires (2 <= (a) && (a) <= 100) && (2 <= (b) && (b) <= 100);
    ensures \result == ((a) * (b) - (a) - (b) + 1);
    ensures \result > 0;
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    //@ assert a * b <= 10000;
    //@ assert a * b - a >= 0;
    //@ assert a * b - a - b >= -99;
    //@ assert a * b - a - b + 1 > 0;
    
    return a * b - a - b + 1;
}
