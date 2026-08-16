#include <stdbool.h>

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  requires 1 <= d <= 100;
  ensures \result == true <==> (a < c && b > d);
*/
bool func(int a, int b, int c, int d)
{
    bool result;
    //@ assert ((a) < (c) && (b) > (d)) <==> (a < c && b > d);
    result = a < c && b > d;
    return result;
}
