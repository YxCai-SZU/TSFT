#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == true <==> (a + d) <= (b + c);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c, unsigned long long d)
{
    // Variable declarations at the top of the scope
    bool result;

    if (a + d <= b + c)
    {
        //@ assert a + d <= b + c;
        result = true;
    }
    else
    {
        //@ assert !(a + d <= b + c);
        result = false;
    }

    return result;
}
