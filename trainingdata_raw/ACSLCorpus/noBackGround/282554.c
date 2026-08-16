#include <stdbool.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 && 1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures a - b >= c ==> \result == 0;
    ensures a - b < c ==> \result == c - (a - b);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;

    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 && 1 <= (c) && (c) <= 20);
    
    if (c - (a - b) > 0)
    {
        result = c - (a - b);
    }
    else
    {
        result = 0;
    }

    //@ assert result == (((a) - (b) >= (c)) ? 0 : (c) - ((a) - (b)));
    //@ assert result >= 0;
    //@ assert result <= c;
    
    if (a - b >= c)
    {
        //@ assert result == 0;
    }
    else
    {
        //@ assert result == c - (a - b);
    }

    return result;
}
