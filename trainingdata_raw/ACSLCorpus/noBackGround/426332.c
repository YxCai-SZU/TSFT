#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    requires a != b && b != c && a != c;
    ensures \result == ((a < c && b > c) || (a > c && b < c));
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int d;
    unsigned int e;
    bool result;

    if (a > b)
    {
        d = a - b;
    }
    else
    {
        d = b - a;
    }

    if (b > c)
    {
        e = b - c;
    }
    else
    {
        e = c - b;
    }

    //@ assert d == (a > b ? a - b : b - a);
    //@ assert e == (b > c ? b - c : c - b);

    if ((a < c && b > c) || (a > c && b < c))
    {
        //@ assert (a < c && b > c) || (a > c && b < c);
        result = true;
    }
    else
    {
        //@ assert !((a < c && b > c) || (a > c && b < c));
        result = false;
    }

    return result;
}
