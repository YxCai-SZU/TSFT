#include <stdbool.h>

/*@
  requires 0 <= a && a <= 100;
  requires 0 <= b && b <= 100;
  requires 0 <= x && x <= 100;
  ensures \result == true <==> ((a) <= (x) && (a) + (b) >= (x));
*/
bool func(int a, int b, int x)
{
    bool result;
    //@ assert ((a) <= (x) && (a) + (b) >= (x)) || !((a) <= (x) && (a) + (b) >= (x));
    
    if (a <= x && a + b >= x) {
        //@ assert ((a) <= (x) && (a) + (b) >= (x));
        result = true;
    } else {
        //@ assert !((a) <= (x) && (a) + (b) >= (x));
        result = false;
    }
    
    return result;
}
