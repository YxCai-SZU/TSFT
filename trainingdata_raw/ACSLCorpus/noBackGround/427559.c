#include <stdbool.h>

/*@
  requires 1 <= a && a <= 10000;
  requires 1 <= b && b <= 10000;
  requires 1 <= c && c <= 10000;
  requires 1 <= d && d <= 10000;
  ensures \result == (c - b <= d - a);
  assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    int min1;
    int min2;
    bool result;

    //@ assert 1 <= a && a <= 10000;
    //@ assert 1 <= b && b <= 10000;
    //@ assert 1 <= c && c <= 10000;
    //@ assert 1 <= d && d <= 10000;

    if (a < b)
    {
        min1 = a;
        //@ assert a <= b && min1 == a;
    }
    else
    {
        min1 = b;
        //@ assert b <= a && min1 == b;
    }

    //@ assert ((min1) == (a) || (min1) == (b));

    if (c < d)
    {
        min2 = c;
        //@ assert c <= d && min2 == c;
    }
    else
    {
        min2 = d;
        //@ assert d <= c && min2 == d;
    }

    //@ assert ((min2) == (c) || (min2) == (d));

    result = (c - b <= d - a);
    return result;
}
