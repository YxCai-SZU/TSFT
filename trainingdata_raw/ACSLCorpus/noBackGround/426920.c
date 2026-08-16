#include <stddef.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result == ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d));
*/
size_t func(size_t a, size_t b, size_t c, size_t d)
{
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    size_t min_ab;
    size_t min_cd;
    size_t result;
    
    min_ab = a < b ? a : b;
    min_cd = c < d ? c : d;
    result = min_ab + min_cd;
    
    //@ assert result == ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d));
    return result;
}
