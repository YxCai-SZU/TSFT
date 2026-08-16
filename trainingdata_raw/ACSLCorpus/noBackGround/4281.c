#include <stdint.h>

/*@
    requires (1 <= (w) <= 100000) && (1 <= (a) <= 100000) && (1 <= (b) <= 100000);
    ensures \result >= 0;
    ensures \result == ((b) > (a) + (w) ? (b) - (a) - (w) :
        (a) > (b) + (w) ? (a) - (b) - (w) :
        0);
    assigns \nothing;
*/
int32_t func(int32_t w, int32_t a, int32_t b)
{
    int32_t result;
    
    //@ assert (1 <= (w) <= 100000) && (1 <= (a) <= 100000) && (1 <= (b) <= 100000);
    
    if (b > a + w)
    {
        //@ assert b > a + w;
        result = b - a - w;
    }
    else if (a > b + w)
    {
        //@ assert a > b + w;
        result = a - b - w;
    }
    else
    {
        //@ assert a <= b + w && b <= a + w;
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result == ((b) > (a) + (w) ? (b) - (a) - (w) :         (a) > (b) + (w) ? (a) - (b) - (w) :         0);
    return result;
}

