#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == (c <= b && b <= d && d <= a + c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    bool result;

    //@ assert (1 <= (a) <= 10000);
    
    if (c <= b && b <= d && d <= a + c)
    {
        //@ assert ((c) <= (b) && (b) <= (d) && (d) <= (a) + (c));
        result = true;
    }
    else
    {
        result = false;
    }
    
    return result;
}
