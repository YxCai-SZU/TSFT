#include <stdint.h>

/*@
    requires (-1000 <= (a) && (a) <= 1000);
    ensures \result == ((a) >= 0 ? (a) * 2 : (a) * -1);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    int64_t result;
    
    //@ assert (-1000 <= (a) && (a) <= 1000);
    
    if (a < 0)
    {
        //@ assert -1000 <= a && a <= 1000;
        result = a * -1;
    }
    else
    {
        //@ assert -1000 <= a && a <= 1000;
        result = a * 2;
    }
    
    //@ assert result == ((a) >= 0 ? (a) * 2 : (a) * -1);
    return result;
}
