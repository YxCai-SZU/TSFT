#include <stdint.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result <= c;
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t result;
    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    result = c - (a - b);
    
    if (result > 0)
    {
        //@ assert result == ((c) - ((a) - (b)));
        //@ assert result <= c;
        return result;
    }
    else
    {
        //@ assert 0 <= c;
        return 0;
    }
}
