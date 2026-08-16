#include <stdbool.h>

/*@
  requires 0 <= x && x <= 255;
  requires 0 <= y && y <= 255;
  ensures \result == (x > y);
*/
bool test_closures(unsigned char x, unsigned char y)
{
    bool result;
    //@ assert (0 <= (x) && (x) <= 255 && 0 <= (y) && (y) <= 255);
    result = (x > y);
    //@ assert ((result) == ((x) > (y)));
    return result;
}
