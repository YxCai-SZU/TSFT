#include <stddef.h>

/*@
    requires (1 <= (x) <= 10000);
    ensures \result == ((((x)) / 100) * 100 + ((((x)) % 100) / 5) * 5);
    assigns \nothing;
*/
size_t func(size_t x)
{
    size_t gohyaku;
    size_t go;
    size_t result;

    //@ assert (1 <= (x) <= 10000);
    
    gohyaku = x / 100;
    go = (x % 100) / 5;
    
    //@ assert gohyaku == x / 100;
    //@ assert go == (x % 100) / 5;
    
    result = gohyaku * 100 + go * 5;
    
    //@ assert result == ((((x)) / 100) * 100 + ((((x)) % 100) / 5) * 5);
    return result;
}
