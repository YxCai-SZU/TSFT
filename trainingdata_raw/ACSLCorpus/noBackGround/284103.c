#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == (c <= b && b <= d && d <= a || a <= c && c <= d && d <= b);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert (1 <= (d) <= 100);
    
    if (c <= b && b <= d && d <= a)
    {
        //@ assert c <= b && b <= d && d <= a;
        return true;
    }
    else if (a <= c && c <= d && d <= b)
    {
        //@ assert a <= c && c <= d && d <= b;
        return true;
    }
    else
    {
        //@ assert !(c <= b && b <= d && d <= a) && !(a <= c && c <= d && d <= b);
        return false;
    }
}
