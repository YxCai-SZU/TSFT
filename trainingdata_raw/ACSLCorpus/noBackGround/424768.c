#include <stdbool.h>

/*@
    requires (1 <= (b) <= (a) <= 20 && 1 <= (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == ((((a)) - ((b))) < (c) ? (c) - (((a)) - ((b))) : 0);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int x;
    int result;
    
    //@ assert (1 <= (b) <= (a) <= 20 && 1 <= (c) <= 20);
    x = a - b;
    
    if (c > x)
    {
        //@ assert c - x >= 0 && c - x <= 20;
        result = c - x;
    }
    else
    {
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result <= c;
    //@ assert result == ((((a)) - ((b))) < (c) ? (c) - (((a)) - ((b))) : 0);
    return result;
}
