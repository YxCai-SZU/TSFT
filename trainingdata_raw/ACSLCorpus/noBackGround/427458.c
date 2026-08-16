#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (c) <= 100);
    ensures \result == (a + b == c || a + c == b || b + c == a);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;

    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;

    if (a + b == c)
    {
        result = true;
        //@ assert a + b == c;
        return result;
    }
    else if (a + c == b)
    {
        result = true;
        //@ assert a + c == b;
        return result;
    }
    else if (b + c == a)
    {
        result = true;
        //@ assert b + c == a;
        return result;
    }
    else
    {
        result = false;
        //@ assert a + b != c && a + c != b && b + c != a;
        return result;
    }
}
