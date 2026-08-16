#include <stdbool.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0 && \result <= c;
    ensures \result == ((c) - ((a) - (b))) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    
    result = c - (a - b);
    
    if (result < 0)
    {
        //@ assert result < 0;
        result = 0;
        //@ assert result == 0;
    }
    else
    {
        //@ assert result >= 0;
        //@ assert result == ((c) - ((a) - (b)));
    }
    
    //@ assert result >= 0 && result <= c;
    //@ assert result == ((c) - ((a) - (b))) || result == 0;
    return result;
}
