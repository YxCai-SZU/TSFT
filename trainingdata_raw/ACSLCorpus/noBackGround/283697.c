#include <stdbool.h>

/*@
  requires 1 <= k <= 100;
  requires 1 <= x <= 100000;
  ensures \result == (500 * k >= x);
*/
bool func(int k, int x)
{
    //@ assert 500 * k <= 500 * 100;
    return 500 * k >= x;
}

/*@
  requires 1 <= k <= 100;
  requires 1 <= x <= 100000;
  ensures \result == (500 * k >= x);
*/
bool func2(int k, int x)
{
    //@ assert 500 * k <= 500 * 100;
    return 500 * k >= x;
}
