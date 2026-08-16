#include <stdbool.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 && 1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= a;
    ensures \result <= c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;

    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 && 1 <= (c) && (c) <= 20);
    //@ assert a - b >= 0;
    
    if (a - b > c)
    {
        result = c;
    }
    else
    {
        result = a - b;
    }

    //@ assert result == (((a) - (b) > (c)) ? (c) : ((a) - (b)));
    //@ assert result >= 0;
    //@ assert result <= a;
    //@ assert result <= c;

    return result;
}
