#include <limits.h>

/*@
    requires a > INT_MIN && a < INT_MAX;
    requires b > INT_MIN && b < INT_MAX;
    requires c > INT_MIN && c < INT_MAX;
    ensures \result == 1 <==> ((a) < (b) && (b) < (c));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    //@ assert a > INT_MIN && a < INT_MAX;
    //@ assert b > INT_MIN && b < INT_MAX;
    //@ assert c > INT_MIN && c < INT_MAX;
    
    if (a < b)
    {
        if (b < c)
        {
            return 1;
        }
        else
        {
            //@ assert a < b && b >= c;
            return 0;
        }
    }
    else
    {
        //@ assert !(a < b);
        return 0;
    }
}
