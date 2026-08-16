#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures \result >= 0;
    ensures \result == a - (b * 2) || \result == 0;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t c;
    
    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100);
    c = a - (b * 2);
    
    //@ assert c == a - (b * 2) || c <= 0;
    
    if (c > 0)
    {
        //@ assert c == a - (b * 2);
        return c;
    }
    else
    {
        //@ assert 0 == 0;
        return 0;
    }
}
