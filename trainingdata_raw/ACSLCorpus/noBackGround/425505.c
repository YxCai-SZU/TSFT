#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (b) <= 100 && 0 <= (x) <= 100);
    ensures \result == (x <= a + b && a <= x);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x)
{
    //@ assert a + b <= 200;
    
    if (x <= a + b && a <= x)
    {
        //@ assert x <= 100 && a <= 100 && b <= 100;
        return true;
    }
    else
    {
        return false;
    }
}
