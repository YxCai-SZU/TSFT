#include <stdbool.h>

/*@
  requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
  ensures \result == true ==> (a < b && b < c);
  ensures \result == true ==> (a + 1 < b && b + 1 < c);
  assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1 <= (c) && (c) <= 100);
    return (a < b) && (b < c) && (a + 1 < b) && (b + 1 < c);
}
