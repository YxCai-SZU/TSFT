#include <limits.h>

/*@
  requires 1 <= n <= 100;
  requires 1 <= m <= 100;
  ensures \result == n * m;
  assigns \nothing;
*/
int func(int n, int m)
{
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= m && m <= 100;
    //@ assert n * m <= 10000;
    
    return n * m;
}
