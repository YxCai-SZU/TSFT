#include <stddef.h>

/*@
    requires (0 <= (a) && (a) <= 100 && 0 <= (p) && (p) <= 100);
    ensures \result >= 0;
    ensures \result <= a * 3 + p;
    ensures \result == (((a) * 3 + (p)) / 2);
*/
size_t func(size_t a, size_t p)
{
    //@ assert a * 3 <= 300;
    //@ assert a * 3 + p <= 400;
    
    return (a * 3 + p) / 2;
}
