#include <stdbool.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == ((c) - ((a) - (b))) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int remain;
    
    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    remain = c - (a - b);
    
    //@ assert remain == ((c) - ((a) - (b)));
    
    if (remain < 0)
    {
        //@ assert remain < 0;
        //@ assert 0 >= 0 && 0 <= c;
        return 0;
    }
    else
    {
        //@ assert remain >= 0;
        //@ assert remain <= c;
        return remain;
    }
}
