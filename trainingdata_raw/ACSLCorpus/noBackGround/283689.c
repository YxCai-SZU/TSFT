#include <stdbool.h>

/*@
    requires (1 <= (a) <= 1000000000 &&
        1 <= (b) <= 1000000000 &&
        1 <= (c) <= 1000000000);
    ensures \result == true <==> ((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    bool result;

    //@ assert 1 <= a <= 1000000000;
    //@ assert 1 <= b <= 1000000000;
    //@ assert 1 <= c <= 1000000000;

    if (a + b == c || a + c == b || b + c == a)
    {
        result = true;
    }
    else
    {
        //@ assert a + b != c && a + c != b && b + c != a;
        result = false;
    }

    //@ assert result == true <==> ((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
    return result;
}
