#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == true <==> (a > c) || (a == c && b > d);
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    bool result = false;

    if (a > c)
    {
        result = true;
    }
    else if (a == c)
    {
        if (b > d)
        {
            result = true;
        }
    }

    //@ assert result == true <==> (a > c) || (a == c && b > d);
    return result;
}
