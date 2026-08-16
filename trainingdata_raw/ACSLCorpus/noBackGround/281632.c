#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == true <==> (a < c && b > c) || (a > c && b < c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool result;
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    if ((a < c && b > c) || (a > c && b < c))
    {
        result = true;
        //@ assert result == true;
    }
    else
    {
        result = false;
        //@ assert result == false;
    }
    
    //@ assert result == true <==> (a < c && b > c) || (a > c && b < c);
    return result;
}
