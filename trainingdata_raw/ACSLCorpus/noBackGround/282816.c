#include <stdbool.h>

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  requires 1 <= d <= 100;
  ensures \result == ((a > c && a - c >= d) || (c > a && c - a >= d));
*/
bool func(int a, int b, int c, int d)
{
    int max_val;
    int diff1;
    int diff2;
    bool result;

    max_val = (a > c) ? a : c;
    diff1 = max_val - a;
    diff2 = max_val - c;

    //@ assert diff1 >= 0 && diff2 >= 0;
    //@ assert diff1 + diff2 == max_val - a + max_val - c;

    if ((a > c && a - c >= d) || (c > a && c - a >= d))
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
