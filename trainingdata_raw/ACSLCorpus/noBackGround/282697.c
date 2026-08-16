#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    ensures \result == true <==> ((a) < (b) && (c) < (d) && (b) <= 10000 && (d) <= 10000);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    //@ assert (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    
    if (a < b && c < d)
    {
        if (b <= 10000 && d <= 10000)
        {
            //@ assert ((a) < (b) && (c) < (d) && (b) <= 10000 && (d) <= 10000);
            return true;
        }
        else
        {
            //@ assert b > 10000 || d > 10000;
            return false;
        }
    }
    else
    {
        //@ assert a >= b || c >= d;
        return false;
    }
}
