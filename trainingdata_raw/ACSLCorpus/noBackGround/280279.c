#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (b) <= 100 && 0 <= (x) <= 100);
    ensures \result == (a <= x && (x - a) <= b);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x)
{
    bool result;

    //@ assert 0 <= a <= 100;
    //@ assert 0 <= b <= 100;
    //@ assert 0 <= x <= 100;

    if (a > x)
    {
        result = false;
    }
    else if ((x - a) <= b)
    {
        //@ assert 0 <= a * b <= 10000;
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == (a <= x && (x - a) <= b);
    return result;
}
