#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= -1 && \result <= 3;
    ensures \result == -1 ==> (a != b && b != c && a != c);
    ensures \result == 3 ==> (a == b && b == c);
    ensures \result == 0 ==> 
        (a != b && b != c && a == c) || 
        (a != c && b == c) || 
        (a == b && b != c);
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    int32_t result;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    if (a == b && b == c)
    {
        result = 3;
        //@ assert result == 3 && a == b && b == c;
    }
    else if (a != b && b != c && a != c)
    {
        result = -1;
        //@ assert result == -1 && a != b && b != c && a != c;
    }
    else
    {
        result = 0;
        //@ assert result == 0 && ((a != b && b != c && a == c) || (a != c && b == c) || (a == b && b != c));
    }
    
    //@ assert result >= -1 && result <= 3;
    return result;
}
