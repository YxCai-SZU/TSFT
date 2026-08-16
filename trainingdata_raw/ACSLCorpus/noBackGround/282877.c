#include <stdbool.h>

/*@
  requires (0 <= (x) && (x) <= 1 &&
      0 <= (a) && (a) <= 100 &&
      0 <= (b) && (b) <= 100);
  ensures (((x) == 1 && (\result) == (a)) || ((x) == 0 && (\result) == (b)));
*/
int func(int x, int a, int b)
{
    int result;
    //@ assert 0 <= x && x <= 1;
    
    if (x == 1) {
        result = a;
        //@ assert x == 1 && result == a;
    } else {
        //@ assert x == 0;
        result = b;
        //@ assert x == 0 && result == b;
    }
    
    //@ assert (((x) == 1 && (result) == (a)) || ((x) == 0 && (result) == (b)));
    return result;
}
