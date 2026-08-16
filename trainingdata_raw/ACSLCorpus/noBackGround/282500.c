#include <stdbool.h>

/*@
    requires (1 <= (x) && (x) < (y) && (y) < 10000 && (x) > 0 && (y) > 0);
    ensures \result == x + y;
    assigns \nothing;
*/
int func(int x, int y)
{
    int result;
    int i;

    //@ assert (1 <= (x) && (x) < (y) && (y) < 10000 && (x) > 0 && (y) > 0);
    
    i = 0;
    /*@
        loop invariant 0 <= i <= x;
        loop invariant (1 <= (x) && (x) < (y) && (y) < 10000 && (x) > 0 && (y) > 0);
        loop assigns i;
        loop variant x - i;
    */
    while (i < x)
    {
        i = i + 1;
    }
    
    //@ assert x + y < 20000;
    
    result = x + y;
    //@ assert result == x + y;
    
    return result;
}
