#include <stdbool.h>

/*@
    requires 1 <= a <= 1000000000000000000;
    requires 1 <= b <= 1000000000000000000;
    requires 1 <= c <= 1000000000000000000;
    ensures \result == true <==> ((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    //@ assert a + b <= 18446744073709551615;
    //@ assert a + c <= 18446744073709551615;
    //@ assert b + c <= 18446744073709551615;
    
    if (a + b == c || a + c == b || b + c == a)
    {
        return true;
    }
    else
    {
        return false;
    }
}
