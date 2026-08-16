#include <stdbool.h>

/*@
    requires \valid(xs + (0..1));
    requires ((2) == 2 &&
        1 <= (xs)[0] <= 100 &&
        1 <= (xs)[1] <= 100);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == ((xs[0]) <= 2 * (xs[1]) ? 0 : (xs[0]) - 2 * (xs[1]));
*/
int func(int *xs)
{
    int result;
    
    //@ assert ((2) == 2 &&         1 <= (xs)[0] <= 100 &&         1 <= (xs)[1] <= 100);
    
    if (xs[0] <= xs[1] * 2)
    {
        result = 0;
    }
    else
    {
        //@ assert xs[0] > xs[1] * 2;
        result = xs[0] - (xs[1] * 2);
    }
    
    //@ assert result == ((xs[0]) <= 2 * (xs[1]) ? 0 : (xs[0]) - 2 * (xs[1]));
    return result;
}
