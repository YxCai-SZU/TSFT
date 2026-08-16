#include <stdbool.h>

/*@
  requires 1 <= n <= 100;
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  ensures \result == true <==> ((n) + (a) >= (b));
*/
bool func(int n, int a, int b)
{
    bool state;
    state = true;

    if (n + a < b)
    {
        state = false;
    }

    //@ assert state == true <==> ((n) + (a) >= (b));
    return state;
}
