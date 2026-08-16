#include <stdbool.h>

/*@
  requires 1 <= a <= 10;
  requires 1 <= b <= 10;
  requires 1 <= c <= 10;
  ensures \result == (c - b == b - a);
*/
bool func(int a, int b, int c)
{
    int diff1;
    int diff2;
    bool result;

    diff1 = b - a;
    diff2 = c - b;
    result = false;

    //@ assert diff1 == b - a;
    //@ assert diff2 == c - b;

    if (diff1 == diff2)
    {
        result = true;
    }

    //@ assert result == (diff1 == diff2);
    return result;
}
