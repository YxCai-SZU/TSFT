#include <stdint.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result == ((c) >= (a) - (b) + 1 ? (a) - (b) + 1 : (c));
    ensures \result >= 0;
    ensures \result <= c;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t result;
    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    
    if (c >= a - b + 1)
    {
        //@ assert a - b + 1 >= 0;
        //@ assert a - b + 1 <= c;
        result = a - b + 1;
    }
    else
    {
        //@ assert c >= 0;
        //@ assert c <= c;
        result = c;
    }
    
    //@ assert result == ((c) >= (a) - (b) + 1 ? (a) - (b) + 1 : (c));
    return result;
}
