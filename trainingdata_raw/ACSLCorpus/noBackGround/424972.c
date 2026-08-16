#include <stdbool.h>

/*@
  requires 1 <= X <= 100;
  requires 1 <= Y <= 100;
  ensures \result == true <==> (Y % 2 == 0 && X + Y / 2 <= 100);
*/
bool func(unsigned int X, unsigned int Y)
{
    bool ok;
    ok = false;
    if (Y % 2 == 0)
    {
        ok = (X + Y / 2) <= 100;
    }
    //@ assert ok == true <==> (Y % 2 == 0 && X + Y / 2 <= 100);
    return ok;
}
