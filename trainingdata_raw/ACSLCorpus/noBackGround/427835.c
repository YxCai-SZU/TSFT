#include <stdbool.h>

/*@
    requires a >= 1 && a <= 100;
    requires b >= 1 && b <= 100;
    requires c >= 1 && c <= 100;
    ensures \result == true <==> (a + b == c || a + c == b || b + c == a);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    bool result = false;

    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    //@ assert c >= 1 && c <= 100;

    if (a + b == c || a + c == b || b + c == a)
    {
        result = true;
    }

    //@ assert result == true <==> (a + b == c || a + c == b || b + c == a);
    return result;
}
