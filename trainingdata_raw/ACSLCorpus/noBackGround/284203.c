#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (a + b == c || b + c == a || c + a == b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool res = false;

    //@ assert 2 <= a + b <= 200;
    //@ assert 2 <= b + c <= 200;
    //@ assert 2 <= c + a <= 200;

    if (a + b == c)
    {
        res = true;
    }
    if (b + c == a)
    {
        res = true;
    }
    if (c + a == b)
    {
        res = true;
    }
    return res;
}
