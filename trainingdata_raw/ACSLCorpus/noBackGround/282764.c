#include <stdbool.h>

/*@
  requires a != 0;
  requires b != 0;
  requires c != 0;
  ensures \result == (a > 0 && b > 0 && c > 0);
*/
bool example(int a, int b, int c)
{
    //@ assert a > 0 && b > 0 && c > 0 ==> (a > 0 && b > 0 && c > 0);
    return a > 0 && b > 0 && c > 0;
}
