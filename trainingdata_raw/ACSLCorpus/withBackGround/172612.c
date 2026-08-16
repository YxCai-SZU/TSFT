#include <stdbool.h>

/*@ predicate diff_le(integer x, integer y, integer d) =
      (x > y ? x - y : y - x) <= d;
*/

/*@
  requires 1 <= a <= 10000;
  requires 1 <= b <= 10000;
  requires 1 <= c <= 10000;
  requires 1 <= d <= 10000;
  ensures \result == true <==>
           diff_le(a, b, d) || diff_le(a, c, d) || diff_le(b, c, d) ||
           diff_le(b, a, d) || diff_le(c, a, d) || diff_le(c, b, d);
*/
bool func(int a, int b, int c, int d)
{
    int diff1;
    int diff2;
    int diff3;
    int diff4;
    int diff5;
    int diff6;
    bool result;

    diff1 = (a > b) ? (a - b) : (b - a);
    diff2 = (a > c) ? (a - c) : (c - a);
    diff3 = (b > c) ? (b - c) : (c - b);
    diff4 = (b > a) ? (b - a) : (a - b);
    diff5 = (c > a) ? (c - a) : (a - c);
    diff6 = (c > b) ? (c - b) : (b - c);

    if (diff1 <= d || diff2 <= d || diff3 <= d ||
        diff4 <= d || diff5 <= d || diff6 <= d)
    {
        result = true;
    }
    else
    {
        //@ assert diff1 > d && diff2 > d && diff3 > d && diff4 > d && diff5 > d && diff6 > d;
        result = false;
    }

    return result;
}
