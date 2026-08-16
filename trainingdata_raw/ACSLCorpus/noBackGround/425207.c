#include <stdbool.h>

/*@
    requires 0 <= a <= 1000000000;
    requires 0 <= b <= 1000000000;
    requires 0 <= c <= 1000000000;
    requires a <= b;
    ensures \result == true <==> (c >= a && c <= b);
    ensures \result == false <==> !(c >= a && c <= b);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert a <= b;

    if (c >= a && c <= b)
    {
        //@ assert c >= a && c <= b;
        result = true;
    }
    else
    {
        //@ assert !(c >= a && c <= b);
        result = false;
    }

    return result;
}
