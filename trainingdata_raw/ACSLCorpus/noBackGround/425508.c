#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == true <==> (c >= a && c <= a + b);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    // Variable declarations at scope top
    bool result;

    if (c >= a && c <= a + b)
    {
        result = true;
        //@ assert result == true;
    }
    else
    {
        //@ assert c < a || c > a + b;
        result = false;
        //@ assert result == false;
    }

    return result;
}
