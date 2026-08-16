#include <stdbool.h>

/*@
  requires ((1) <= (a) && (a) <= (100));
  requires ((1) <= (b) && (b) <= (100));
  requires ((1) <= (x) && (x) <= (200));
  ensures \result == (x >= a && x <= a + b);
*/
bool func(int a, int b, int x)
{
    //@ assert ((1) <= (a) && (a) <= (100));
    //@ assert ((1) <= (b) && (b) <= (100));
    //@ assert ((1) <= (x) && (x) <= (200));
    
    bool result;
    result = (x >= a && x <= a + b);
    return result;
}
