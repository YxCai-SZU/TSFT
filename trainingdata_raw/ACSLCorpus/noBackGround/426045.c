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
    int result;
    int ret;

    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    
    result = c - (a - b);
    
    if (result < 0)
    {
        ret = 0;
    }
    else
    {
        ret = result;
    }
    
    //@ assert ret >= 0 && ret <= c;
    //@ assert ret == ((c) - ((a) - (b))) || ret == 0;
    
    return ret;
}
