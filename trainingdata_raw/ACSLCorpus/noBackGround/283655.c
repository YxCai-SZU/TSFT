#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    requires a + b + c == 180;
    ensures \result == true <==> (a == 90 || b == 90 || c == 90);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;

    //@ assert a + b + c == 180;
    
    if (a == 90 || b == 90 || c == 90)
    {
        //@ assert a == 90 || b == 90 || c == 90;
        result = true;
    }
    else
    {
        //@ assert a != 90 && b != 90 && c != 90;
        result = false;
    }

    return result;
}
