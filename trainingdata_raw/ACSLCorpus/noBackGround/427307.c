#include <stdbool.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures a - b >= c ==> \result == 0;
    ensures a - b < c ==> \result == c - (a - b);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int diff;

    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    diff = a - b;
    
    if (diff >= c)
    {
        //@ assert diff >= c;
        result = 0;
    }
    else
    {
        //@ assert diff < c;
        result = c - diff;
    }

    //@ assert result >= 0;
    return result;
}
