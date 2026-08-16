#include <stdbool.h>

/*@
  requires x != y;
  requires ((x) == 1 || (x) == 2 || (x) == 3) && ((y) == 1 || (y) == 2 || (y) == 3);
  ensures ((\result) == 1 || (\result) == 2 || (\result) == 3);
  ensures \result != x && \result != y;
*/
int func(int x, int y)
{
    int ans;
    ans = 6 - x - y;
    //@ assert ((ans) == 1 || (ans) == 2 || (ans) == 3);
    //@ assert ans != x && ans != y;
    return ans;
}
