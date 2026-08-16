#include <stddef.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    ensures \result <= b;
    ensures \result >= ((b) > (((n)) * ((a))) ? (b) - (((n)) * ((a))) : 0);
    assigns \nothing;
*/
size_t func(size_t n, size_t a, size_t b)
{
    // Variable declarations at top of scope
    size_t train;
    size_t result;

    //@ assert (1 <= (n) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    
    train = n * a;
    
    if (train > b)
    {
        result = 0;
        //@ assert result == 0;
    }
    else
    {
        //@ assert train <= b;
        result = b - train;
        //@ assert result == b - train;
    }
    
    //@ assert result <= b;
    //@ assert result >= ((b) > (((n)) * ((a))) ? (b) - (((n)) * ((a))) : 0);
    return result;
}
